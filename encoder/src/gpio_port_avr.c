
#include "gpio_port_avr.h"

void GPIO_init(GPIOdef* gpio_addr, GPIOdef gpio)
{
    gpio_addr->DDR = gpio.DDR;
    gpio_addr->PORT = gpio.PORT;
}

void GPIO_write(GPIOdef* gpio_addr, uint8_t gpio_state)
{
    gpio_addr->PORT = gpio_state;
}

uint8_t GPIO_read(GPIOdef* gpio_addr)
{
    return gpio_addr->PIN;    
}

void GPIO_setbit(GPIOdef* gpio_addr, uint8_t gpio_mask)
{
    gpio_addr->PORT |= gpio_mask;
}

void GPIO_clearbit(GPIOdef* gpio_addr, uint8_t gpio_mask)
{
    gpio_addr->PORT &= ~gpio_mask;    
}

void GPIO_togglebit(GPIOdef* gpio_addr, uint8_t gpio_mask)
{
    gpio_addr->PORT ^= gpio_mask;
}

uint8_t GPIO_readbit(GPIOdef* gpio_addr, uint8_t gpio_mask)
{
    return ((gpio_addr->PIN) & gpio_mask);    
}
