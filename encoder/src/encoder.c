
#include "encoder.h"

/*
	Przed uproszeniem warunkow w instrukcjach IF
	Program:     368 bytes (0.3% Full)
	Po uproszczeniu warunkow w instrukcjach IF
	Program:     326 bytes (0.2% Full)
 */

static int8_t encoder_cnt = 0;

void encoder_sm(void)
{
    static uint8_t state = state_0;
    
    switch(state)
    {
        // stan poczatkowy
    	case state_0: 
            if (encoder_read_R() == ENCODER_PIN_ON)  state = state_R1;
    	    if (encoder_read_L() == ENCODER_PIN_ON)  state = state_L1;
    	    break;
        
        // obrot w prawo
    	case state_R1:
    	    if (encoder_read_R() == ENCODER_PIN_OFF) state = state_0;
    	    if (encoder_read_L() == ENCODER_PIN_ON)  state = state_R2;
    	    break;
    	case state_R2:
    	    if (encoder_read_R() == ENCODER_PIN_OFF) state = state_R3;
    	    if (encoder_read_L() == ENCODER_PIN_OFF) state = state_R1;
    	    break;
    	case state_R3:
        	if (encoder_read_R() == ENCODER_PIN_ON)  state = state_R2;
        	if (encoder_read_L() == ENCODER_PIN_OFF) state = state_R4;
    	    break;
    	case state_R4:
    	    encoder_cnt++;
    	    state = state_0;
        	break;
       	
        // obrot w lewo
    	case state_L1:
    	    if (encoder_read_R() == ENCODER_PIN_ON)  state = state_L2;
    	    if (encoder_read_L() == ENCODER_PIN_OFF) state = state_0;
    	    break;
    	case state_L2:
    	    if (encoder_read_R() == ENCODER_PIN_OFF) state = state_L1;
    	    if (encoder_read_L() == ENCODER_PIN_OFF) state = state_L3;
    	    break;
    	case state_L3:
    	    if (encoder_read_R() == ENCODER_PIN_OFF) state = state_L4;
    	    if (encoder_read_L() == ENCODER_PIN_ON)  state = state_L2;
    	    break;
    	case state_L4:
    	    encoder_cnt--;
    	    state = state_0;
    	    break;
        default:
            state = state_0;
    }
}

int8_t encoder_read(void)
{
    return encoder_cnt;
}
