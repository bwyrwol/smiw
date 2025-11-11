
#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <stddef.h> // tu zdefiniowany NULL

#undef PORTA
#define PORTA ((GPIOdef*) 0x39)
#undef PORTB
#define PORTB ((GPIOdef*) 0x36)
#undef PORTC
#define PORTC ((GPIOdef*) 0x33)
#undef PORTD
#define PORTD ((GPIOdef*) 0x30)

#define GPIO_PIN_INPUT  0
#define GPIO_PIN_OUTPUT 1
#define GPIO_PIN_LOW    0
#define GPIO_PIN_HIGH   1

typedef struct
{
    uint8_t PIN;
    uint8_t DDR;
    uint8_t PORT;
} GPIOdef;

class GPIO
{
    protected:
        volatile GPIOdef* addr;

    public:
        GPIO(volatile GPIOdef* gpio_addr): addr(gpio_addr) {};
       ~GPIO()
        {
            addr->PORT = 0;
            addr->DDR  = 0;
            addr = NULL;
        };
        
        void setDIR(uint8_t dir);
        void setPORT(uint8_t value);
        uint8_t getPORT();
        uint8_t getPIN();

        void setPinDir(uint8_t pin, uint8_t dir);
        void setPinValue(uint8_t pin, uint8_t bit);
        uint8_t getPinValue(uint8_t pin);
};

#endif /* GPIO_H_ */