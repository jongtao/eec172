#ifndef GAME_H
#define GAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <Adafruit_GFX.h>
#include "Adafruit_SSD1351.h"
#include <SPI_OLED.h>
#include "infrared.h"

#define SCALE 8

#define WORLD_HEIGHT 16
#define WORLD_LENGTH 16

#define SCREEN_HEIGHT 128
#define SCREEN_WIDTH 128

#define POS_HEIGHT (WORLD_HEIGHT*8)
#define POS_LENGTH (WORLD_LENGTH*8)

#define MAN_WIDTH 5
#define MAN_HEIGHT 10
#define MAN_HEAD 3
#define GRAVITY 3

typedef enum
{
	NOTHING,
	GRASS,
	DIRT,
	ROCK,
} Block_type;



void generate_world(int seed);

void draw_world(uint8_t x, uint8_t y);
void draw_man(void);
void game_update(void);
void update_action(void);
void update_dig(void);
void check_horizontal(void);
void check_vertical(void);

void game_init(Adafruit_SSD1351* screen, Button* button, unsigned seed);

#ifdef __cplusplus
}
#endif


#endif // GAME_H
