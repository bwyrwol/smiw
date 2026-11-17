
#include <avr/io.h>
#include <stdint.h>
#include "gpio_port_avr.h"
#include "systimer_port_avr.h"
#include "encoder_port_avr.h"
#include "encoder.h"

#define ENCODER_PIN_L   PB0
#define ENCODER_PIN_R   PB1
#define ENCODER_PORT    PORTB

#define LED_PORT        PORTA

int main(void)
{
    encoder_port_avr_init(ENCODER_PORT, ENCODER_PIN_R, ENCODER_PIN_L);

    GPIOdef GPIOled;
        GPIOled.DDR = 0xFF;
        GPIOled.PORT = 0xFF;
    GPIO_init(LED_PORT, GPIOled);    
    
    while (1) 
    {
        encoder_sm();
        GPIO_write(LED_PORT, ~encoder_read());
    }
}
