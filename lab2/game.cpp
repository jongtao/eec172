#include "game.h"

#include "stdlib.h"
#include "stdint.h"
#include "string.h"

// screen functions
Adafruit_SSD1351* screen;
Button* input;

uint8_t world[WORLD_LENGTH][WORLD_HEIGHT]; // Top left is zero, zero

short x_pos, y_pos; // top right of dude
short x_vel, y_vel;


void generate_world(int seed)
{
	int l,b;
	int antiheight;
	int delta;
	uint8_t heights[WORLD_LENGTH];
	
	srand(seed);
	
	for(l=0; l<WORLD_LENGTH; l++)
	{
		delta = rand() % WORLD_HEIGHT;

		switch(l)
		{
			case 0:
				antiheight = (delta+WORLD_HEIGHT/2)/2;
				break;
			case 1:
				antiheight = (delta+heights[l-1])/2;
				break;
			default:
				antiheight = (delta+heights[l-1]+heights[l-2])/3;
		}; // switch l

		heights[l] = antiheight;


		for(b=0; b<WORLD_HEIGHT; b++)
		{
			if(b == antiheight)
				world[l][b] = GRASS;
			else
				if(b > antiheight)
				{
					if(b < (antiheight+3))
						world[l][b] = DIRT;
					else
						world[l][b] = ROCK;
				} // if under dirt
				else
					world[l][b] = NOTHING;
		} // for all blocks in column
	} // for whole length
} // generate_world()


void draw_world(uint8_t x, uint8_t y)
{
	uint8_t i, j; // start drawing from x, y

	for(j=x; j<(x+SCREEN_WIDTH); j+=SCALE)
	{
		for(i=y; i<(y+SCREEN_HEIGHT); i+=SCALE) // for vertical world showing in screen
		{
			switch(world[j/SCALE][i/SCALE])
			{
				case GRASS:
					screen->fillRect(j-x,i-y,SCALE,SCALE,0x07E0);
					break;
				case DIRT:
					screen->fillRect(j-x,i-y,SCALE,SCALE,0x6969);
					break;
				case ROCK:
					screen->fillRect(j-x,i-y,SCALE,SCALE,0x7BEF);
					break;
				case NOTHING:
					screen->fillRect(j-x,i-y,SCALE,SCALE,0x7FFF);
			}; // switch world
		} // for j
	} // for i
} // draw()



void draw_man(void)
{
	screen->fillRect(x_pos,y_pos,MAN_WIDTH,MAN_HEAD,0xFFE0);
	screen->fillRect(x_pos,y_pos+MAN_HEAD,MAN_WIDTH,MAN_HEIGHT-MAN_HEAD,0xF800);
} // draw_man()



void game_update(void)
{
	update_action();
	update_dig();
	draw_world(0,0);
	draw_man();
} //update()



void update_action(void)
{
	uint8_t jumping = 0;
	if(input->pressing)
	{
		/*
		if(input->cmd == 0x0D)
			y_vel += 3;
			*/

		if(input->cmd == 0x4C) // jump
			if((world[x_pos/SCALE][(y_pos+MAN_HEIGHT)/SCALE] != NOTHING ||
				world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos+MAN_HEIGHT)/SCALE] != NOTHING)
				&& world[(x_pos)/SCALE][(y_pos)/SCALE] == NOTHING &&
				world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos)/SCALE] == NOTHING
				)
			{
				y_vel -= 10;
				jumping = 1;
			}// if on the ground and no block above

		if(input->cmd == 0x03) // left
			x_vel -=3;

		if(input->cmd == 0x02) // right
			x_vel +=3;
	} // if is pressing

	if(!jumping)
		y_vel+=GRAVITY;

	if(x_vel>0) x_vel--;
	if(x_vel<0) x_vel++;
		
	if(y_vel>0) y_vel--;
	if(y_vel<0) y_vel++;

	if(y_vel < -10) y_vel = -10;
	if(y_vel > 10) y_vel = 10;

	if(x_vel < -4) x_vel = -4;
	if(x_vel > 4) x_vel = 4;

	x_pos += x_vel;
	y_pos += y_vel;

	if(y_vel == 10 || y_vel < -7)
	{
		check_vertical();
		check_horizontal();
	}
	else
	{
		check_horizontal();
		check_vertical();
	}
} // update_action()


void update_dig(void)
{
	int l_dig, r_dig, d_dig, u_dig;

	l_dig = x_pos/SCALE - 1;
	if(l_dig<0) l_dig = 0;
	r_dig = x_pos/SCALE + 1;
	d_dig = y_pos/SCALE + 2;
	u_dig = y_pos/SCALE;

	
	if(input->pressing)
	{
		if(input->cmd == 0x14)
		{
			if(world[l_dig][(y_pos+MAN_HEIGHT/2)/SCALE] != NOTHING)
				world[l_dig][(y_pos+MAN_HEIGHT/2)/SCALE] = NOTHING;
		} // dig left

		if(input->cmd == 0x16)
		{
			if(world[r_dig][(y_pos+MAN_HEIGHT/2)/SCALE] != NOTHING)
				world[r_dig][(y_pos+MAN_HEIGHT/2)/SCALE] = NOTHING;
		} // dig right

		if(input->cmd == 0x18)
		{
			if(world[(x_pos+MAN_WIDTH/2)/SCALE][d_dig] != NOTHING)
				world[(x_pos+MAN_WIDTH/2)/SCALE][d_dig] = NOTHING;
		} // dig down

		if(input->cmd == 0x12)
		{
			if(world[(x_pos+MAN_WIDTH/2)/SCALE][u_dig] != NOTHING)
				world[(x_pos+MAN_WIDTH/2)/SCALE][u_dig] = NOTHING;
		} // dig up



		if(input->cmd == 0x11)
		{
			if(world[l_dig][u_dig] != NOTHING)
				world[l_dig][u_dig] = NOTHING;
		} // dig left up

		if(input->cmd == 0x13)
		{
			if(world[r_dig][u_dig] != NOTHING)
				world[r_dig][u_dig] = NOTHING;
		} // dig right up

		if(input->cmd == 0x17)
		{
			if(world[l_dig][d_dig] != NOTHING)
				world[l_dig][d_dig] = NOTHING;
		} // dig left down

		if(input->cmd == 0x19)
		{
			if(world[r_dig][d_dig] != NOTHING)
				world[r_dig][d_dig] = NOTHING;
		} // dig right up


	} // if pressing
} // update_dig()


void check_horizontal(void)
{
	// bottom left horizontal
	if(world[x_pos/SCALE][(y_pos+MAN_HEIGHT-5)/SCALE] != NOTHING)
	{
		if(x_vel<0)
			x_vel = 0;
		while(world[x_pos/SCALE][(y_pos+MAN_HEIGHT-5)/SCALE] != NOTHING)
			x_pos++;
	} // if bottom left

	// bottom right horizontal
	if(world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos+MAN_HEIGHT-5)/SCALE] != NOTHING)
	{
		if(x_vel>0)
			x_vel = 0;
		while(world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos+MAN_HEIGHT-5)/SCALE] != NOTHING)
			x_pos--;
	} // if bottom left

} // check_horizontal()



void check_vertical(void)
{
	// Bottom left vertical
	if(world[x_pos/SCALE][(y_pos+MAN_HEIGHT)/SCALE] != NOTHING)
	{
		if(y_vel>0)
			y_vel = 0;
		while(world[x_pos/SCALE][(y_pos+MAN_HEIGHT-1)/SCALE] != NOTHING)
			y_pos--;
	} // if bottom left

	// bottom right vertical
	if(world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos+MAN_HEIGHT)/SCALE] != NOTHING)
	{
		if(y_vel>0)
			y_vel = 0;
		while(world[(x_pos+MAN_WIDTH-1)/SCALE][(y_pos+MAN_HEIGHT-1)/SCALE] != NOTHING)
			y_pos--;
	} // if bottom right

	// top middle
	// bottom right vertical
	if(world[(x_pos+MAN_WIDTH/2-1)/SCALE][(y_pos-5)/SCALE] != NOTHING)
	{
		if(y_vel<0)
			y_vel = 0;
			/*
		while(world[(x_pos+MAN_WIDTH/2-1)/SCALE][(y_pos-5)/SCALE] != NOTHING)
			y_pos++;
			*/
	} // if bottom right

} // check_vertical()



void game_init(Adafruit_SSD1351* handle, Button* button, unsigned seed)
{
	screen = handle;
	input = button;

	generate_world(seed);

	x_pos = POS_LENGTH/2;
	y_pos = -MAN_HEIGHT;
	x_vel = y_vel = 0;

	//draw_world(0,0);	
	//screen->fillRect(64,90,10,10,0x07E0);
} // game_init()
