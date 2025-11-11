
#include "GPIO.h"

void GPIO::setDIR(uint8_t dir)
{
    addr->DDR = dir;
}

void GPIO::setPORT(uint8_t value)
{
    addr->PORT = value;
}

uint8_t GPIO::getPORT()
{
    return addr->PORT;
}

uint8_t GPIO::getPIN()
{
    return addr->PIN;
}

void GPIO::setPinDir(uint8_t pin, uint8_t dir)
{
    if (dir == GPIO_PIN_INPUT)
        addr->DDR &= ~(1 << pin); 
    else
        addr->DDR |= (1 << pin);        
}

void GPIO::setPinValue(uint8_t pin, uint8_t bit)
{
    if (bit == GPIO_PIN_LOW)
        addr->PORT &= ~(1 << pin);
    else
        addr->PORT |= (1 << pin);    
}

uint8_t GPIO::getPinValue(uint8_t pin)
{
    if (((addr->PIN) & (1 << pin)) == 0)
        return GPIO_PIN_LOW;
    else
        return GPIO_PIN_HIGH;
}
