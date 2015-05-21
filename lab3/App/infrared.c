#include "infrared.h"



//stc_exint_config_t exint_config; // External Int
WyzBee_exint_config_t WyzBeeExtIntConfig;
stc_dt_channel_config_t dt_config; // Timer





// State machine
uint8_t state, is_first;
uint32_t prev_t, delta_mark, delta_space;
uint8_t data_count;

// Key Buffers
uint32_t stream; // holds bits as they come in
Button key;
volatile uint32_t buffer; // test buffer



void IR_ISR(void)
{
	uint32_t tmp_time;
	//if(exint_config.aenLevel[IR_INT_CHAN] == ExIntFallingEdge) // if logical rise
	if(WyzBeeExtIntConfig.aenLevel[IR_INT_CHAN] == ExIntFallingEdge)
	{
		// Evaluate Time
		if(!is_first) // not the first cycle
		{
			delta_space = prev_t - Dt_ReadCurCntVal(DtChannel0);

			// Evaluate IR State Machine
			switch(state)
			{
				case WAIT:
					if((delta_mark >= (HEAD_MARK - TOLERANCE)) &&
						(delta_mark <= (HEAD_MARK + TOLERANCE)))
					{
						if((delta_space >= (HEAD2DATA_SPACE - TOLERANCE)) &&
							(delta_space <= (HEAD2DATA_SPACE + TOLERANCE)))
						{
							if(key.pressing) // can only press one button on remote
								key.pressing = 0;

							state = DATA;
						} // go to DATA

						if((delta_space >= (HEAD2REPEAT_SPACE - TOLERANCE)) &&
							(delta_space <= (HEAD2REPEAT_SPACE + TOLERANCE)))
						{
							state = END;
						} // go to END (Repeat)

						data_count = 0;
						stream = 0;
					} // if HEAD found
					break;

				case DATA:
					state = WAIT;

					if((delta_space >= (DATA_1_SPACE - TOLERANCE)) &&
						(delta_space <= (DATA_1_SPACE + TOLERANCE)))
					{
						stream |= 0x1 << data_count;
						state = DATA;
					} // if one
					else
						if((delta_space >= (DATA_0_SPACE - TOLERANCE)) &&
							(delta_space <= (DATA_0_SPACE + TOLERANCE)))
							state = DATA;

					data_count++;
					if(data_count == IR_WORD_SIZE)
					{
						if(extract(stream, &key)) // attempt to extract
						{
							key.pressing = 0;
							state = WAIT; // abort data
						}
						else
						{
							key.pressing = 1;
							state = END;
						} // else data is good
					}
					break;

				case END:
					state = WAIT;
					break;

				default:
					state = WAIT;
			} // switch state


		} // if not first
		else // else is the first cycle (no data)
		{
			is_first = 0;
		} // is first

		// Reset and Start Timer
		Dt_DisableCount(DtChannel0);
		Dt_WriteLoadVal(TIMEOUT, DtChannel0); // ~0.21 Seconds Timeout
		Dt_EnableCount(DtChannel0);

/*
		// Set interrupt to Rising (logical fall)
		Exint_DisableChannel(IR_INT_CHAN);
		exint_config.aenLevel[IR_INT_CHAN] = ExIntRisingEdge;
		Exint_Init(&exint_config);
		Exint_EnableChannel(IR_INT_CHAN);
*/
		WyzBee_Exint_DisableChannel(IR_INT_CHAN);
		WyzBeeExtIntConfig.aenLevel[IR_INT_CHAN] = ExIntRisingEdge;
		WyzBee_Exint_IR_Init(&WyzBeeExtIntConfig);
		WyzBee_Exint_EnableChannel(IR_INT_CHAN);
		
		prev_t = TIMEOUT;
	} // if Falling Edge
	else // Rising Edge
	{
		tmp_time = Dt_ReadCurCntVal(DtChannel0);
		delta_mark = prev_t - tmp_time;	
		prev_t = tmp_time;
/*
		// Set interrupt to Falling (logical rise)
		Exint_DisableChannel(IR_INT_CHAN);
		exint_config.aenLevel[IR_INT_CHAN] = ExIntFallingEdge;
		Exint_Init(&exint_config);
		Exint_EnableChannel(IR_INT_CHAN);
*/
		WyzBee_Exint_DisableChannel(IR_INT_CHAN);
		WyzBeeExtIntConfig.aenLevel[IR_INT_CHAN] = ExIntFallingEdge;
		WyzBee_Exint_IR_Init(&WyzBeeExtIntConfig);
		WyzBee_Exint_EnableChannel(IR_INT_CHAN);
		
	} // else Rising Edge

} // IR_ISR()



void timer_ISR(void) // triggers on TIMEOUT
{
	key.pressing = 0;
	state = WAIT;
} // timer_ISR()



uint8_t extract(uint32_t word, volatile Button* button)
{
	uint8_t addr, addr_, cmd, cmd_;

	addr = word & 0x000000FF;
	addr_ = ~((word & 0x0000FF00) >> 8);
	cmd = (word & 0x00FF0000) >> 16;
	cmd_ = ~((word & 0xFF000000) >> 24);

	if((addr != addr_) || (cmd != cmd_)) // if error
	{
		return 1; //error
	} // if error found
	else
	{
		button->addr = addr;
		button->cmd = cmd;
		return 0;
	} // else ok
} // extract()


void infrared_init(void)
{
	// State Machine
	state = WAIT;
	is_first = 1; // no cycle data
	prev_t = delta_space = delta_mark = 0;

	// Event Queue	
	key.pressing = 0; // button is not pressed continuously

/*
	// External interrupt on INT02_1
  PDL_ZERO_STRUCT(exint_config);
	exint_config.abEnable[IR_INT_CHAN] = TRUE;
  exint_config.aenLevel[IR_INT_CHAN] = ExIntFallingEdge;
  exint_config.apfnExintCallback[IR_INT_CHAN] = &IR_ISR;
  
  SetPinFunc_INT02_1(0u);
  Exint_Init(&exint_config);
  Exint_EnableChannel(IR_INT_CHAN);
	*/
	WyzBee_PDL_ZERO(WyzBeeExtIntConfig);
	WyzBeeExtIntConfig.abEnable[IR_INT_CHAN] = TRUE;
	WyzBeeExtIntConfig.aenLevel[IR_INT_CHAN] = ExIntFallingEdge;
	WyzBeeExtIntConfig.apfnExintCallback[IR_INT_CHAN] = &IR_ISR;
	WyzBee_Exint_IR_Init(&WyzBeeExtIntConfig);
	WyzBee_Exint_EnableChannel(IR_INT_CHAN);


	// Timer
	// 312500 with 256 prescale = 1 second
	// Clock = 80Mhz
	PDL_ZERO_STRUCT(dt_config);

	dt_config.u8Mode = DtFreeRun;
	dt_config.u8PrescalerDiv = DtPrescalerDiv256;
	dt_config.u8CounterSize = DtCounterSize32;

	Dt_Init(&dt_config, DtChannel0);
	Dt_WriteBgLoadVal(TIMEOUT, DtChannel0);
	Dt_WriteLoadVal(TIMEOUT, DtChannel0); // ~0.21 Seconds Timeout
	Dt_EnableInt(&timer_ISR, DtChannel0); // Timeout Interrupt
} // infrared_init();

