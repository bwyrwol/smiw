
#include "encoder_port_avr.h"

static GPIOdef* encoder_gpio_addr;
static uint8_t encoder_gpio_pin_l;
static uint8_t encoder_gpio_pin_r;

void encoder_port_avr_init(GPIOdef* enc_gpio_addr, uint8_t enc_pin_r, uint8_t enc_pin_l)
{
    GPIOdef GPIO;
        //GPIO.DDR = ~((1 << enc_pin_r) | (1 << enc_pin_l));
        GPIO.PORT = ((1 << enc_pin_r) | (1 << enc_pin_l));
    GPIO_init(enc_gpio_addr, GPIO);
    
    encoder_gpio_addr  = enc_gpio_addr;
    encoder_gpio_pin_r = enc_pin_r;
    encoder_gpio_pin_l = enc_pin_l;
    
    systimer_init(5);
}

void systimer_callback(void)
{
    encoder_sm();    
}

uint8_t encoder_read_L(void)
{
    if (GPIO_readbit(encoder_gpio_addr, (1 << encoder_gpio_pin_l)) == 0)
        return ENCODER_PIN_ON;
    else
        return ENCODER_PIN_OFF;
}

uint8_t encoder_read_R(void)
{
    if (GPIO_readbit(encoder_gpio_addr, (1 << encoder_gpio_pin_r)) == 0)
        return ENCODER_PIN_ON;
    else
        return ENCODER_PIN_OFF;    
}
