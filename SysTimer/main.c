
#include <avr/io.h>
#define F_CPU 14745600UL
#include "systimer.h"

void systimer_delay_ms_block(uint16_t time_in_ms)
{
}


uint8_t systimer_delay_ms_noblock(uint16_t time_in_ms)
{
    return 0;
}


int main(void)
{

  systimer_init(123); // in ms
  
  while (1) 
  {

  }
}
