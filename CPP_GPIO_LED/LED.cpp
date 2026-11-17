
#include "LED.h"

void LED::On()
{
    if (_config == ACTIVE_LOW)
        setPinValue(_pin, GPIO_PIN_LOW);
    else
        setPinValue(_pin, GPIO_PIN_HIGH);
}

void LED::Off()
{
    if (_config == ACTIVE_LOW)
        setPinValue(_pin, GPIO_PIN_HIGH);
    else
        setPinValue(_pin, GPIO_PIN_LOW);
}

uint8_t LED::State()
{
    if (_config == ACTIVE_LOW)
    {
        if (getPinValue(_pin) == GPIO_PIN_LOW)
            return LED_IS_ON;
        else
            return LED_IS_OFF;
    }
    else
    {
        if (getPinValue(_pin) == GPIO_PIN_LOW)
            return LED_IS_OFF;
        else
            return LED_IS_ON;        
    }    
}

void LED::Toggle()
{
    if (State() == LED_IS_OFF)
        On();
    else
        Off();
}
