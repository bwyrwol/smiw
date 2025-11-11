
#ifndef LED_H_
#define LED_H_

#include "GPIO.h"

#define ACTIVE_LOW  0
#define ACTIVE_HIGH 1
#define LED_IS_OFF  0
#define LED_IS_ON   1

class LED: private GPIO
{
    private:
        uint8_t	_config;
        uint8_t _pin;
    
    public:
        LED(volatile GPIOdef* port, uint8_t pin, uint8_t config): 
        GPIO(port),
        _config(config),
        _pin(pin)
        {
            setPinDir(pin, GPIO_PIN_OUTPUT);
        };
    
    void On();
    void Off();
    uint8_t State();
    void Toggle();
};

#endif /* LED_H_ */