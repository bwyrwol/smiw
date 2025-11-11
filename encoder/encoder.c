#include <avr\io.h>

/*
	Obsluga enkodera obrotowego (impulsator obrotowy)

	Program testujacy - wyswietla na diodach liczbe obrotow

	Przed uproszeniem warunkow w instrukcjach IF
	Program:     368 bytes (0.3% Full)
	Po uproszczeniu warunkow w instrukcjach IF
	Program:     326 bytes (0.2% Full)

	Aktywny stan 1
	Dziala!

 */

#define LEDs 		PORTB
#define RotEnc	 	PINA
#define RotEnc_R	PINA0
#define RotEnc_L	PINA1

#define ROTENC_R	(~RotEnc & (1<<RotEnc_R))
#define ROTENC_L	(~RotEnc & (1<<RotEnc_L))

#define state_0		0
#define state_1		1
#define state_2		2
#define state_3		3
#define state_4		4
#define state_5		5
#define state_6		6
#define state_7		7
#define state_8		8

void InitHardware(void);
void InitHardware(void)
{
  // inicjalizacja rejestrow DDR portow
  _SFR_IO8(_SFR_IO_ADDR(LEDs)-1) = 0xFF;

  // wygaszenie diod (aktywny stan L)
  LEDs = 0xFF;

  // wlaczenie rezystorow polaryzujacych dla enkodera
  _SFR_IO8(_SFR_IO_ADDR(RotEnc)+2) |= (1<<RotEnc_R) | (1<<RotEnc_L);
}

int main(void)
{
  InitHardware();

  unsigned char state = state_0;
  unsigned char count = 0;

  for(;;)
    {
	  switch(state)
	  {
		// stan poczatkowy
		case state_0: if (ROTENC_R != 0) state = state_1;
					  if (ROTENC_L != 0) state = state_5;
					  break;
		// obrot w prawo
		case state_1: if (ROTENC_L != 0) state = state_2;
					  if (ROTENC_R == 0) state = state_0;
					  break;
		case state_2: if (ROTENC_L == 0) state = state_1;
					  if (ROTENC_R == 0) state = state_3;
					  break;
		case state_3: if (ROTENC_R != 0) state = state_2;
					  if (ROTENC_L == 0) state = state_4;
					  break;
		case state_4: count += 1;
					  LEDs = ~count;
					  state = state_0;
					  break;
		// obrot w lewo
		case state_5: if (ROTENC_R != 0) state = state_6;
					  if (ROTENC_L == 0) state = state_0;
					  break;
		case state_6: if (ROTENC_L == 0) state = state_7;
					  if (ROTENC_R == 0) state = state_5;
					  break;
		case state_7: if (ROTENC_L != 0) state = state_6;
					  if (ROTENC_R == 0) state = state_8;
					  break;
		case state_8: count -= 1;
					  LEDs = ~count;
					  state = state_0;
					  break;
	  }
	}

  return 0;
}
