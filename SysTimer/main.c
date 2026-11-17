
#include <avr/io.h>
#define F_CPU 14745600UL
#include "systimer.h"

volatile uint16_t systimer_ticks;

void systimer_callback(void)
{
  //PORTD ^= 0b11000000;
  if (systimer_ticks != 0)
    systimer_ticks -= 1;
}


void systimer_delay_ms_block(uint16_t time_in_ms)
{
  systimer_ticks = time_in_ms;
  while (systimer_ticks != 0)
  {
     ;
  } 
}


uint8_t systimer_delay_ms_noblock(uint16_t time_in_ms)
{
    if (systimer_ticks == 0)
    {
      systimer_ticks = time_in_ms;
      return 0;
    }
    else
      return -1;
}


int main(void)
{

  DDRA |= 0xFF;
  PORTA |= 0x33;

  systimer_init(1); // in ms
  
  while (1) 
  {
      //PORTA ^= 0xFF;
      //systimer_delay_ms_block(100);
      
      if (systimer_delay_ms_noblock(100) == 0)
        PORTA ^= 0xFF;
      
      
  }
}
