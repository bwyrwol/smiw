#ifndef GPIO_PORT_AVR_H_
#define GPIO_PORT_AVR_H_

#include <avr/io.h>

#define GPIO0 0x01
#define GPIO1 0x02
#define GPIO2 0x04
#define GPIO3 0x08
#define GPIO4 0x10
#define GPIO5 0x20
#define GPIO6 0x40
#define GPIO7 0x80

typedef struct
{

} GPIOdef;

// podstawowe
void GPIO_init(GPIOdef* gpio_addr, GPIOdef gpio);
void GPIO_write(GPIOdef* gpio_addr, uint8_t gpio_state);
uint8_t GPIO_read(GPIOdef* gpio_addr);

// dodatkowe
void GPIO_setbit(GPIOdef* gpio_addr, uint8_t gpio_mask);
void GPIO_clearbit(GPIOdef* gpio_addr, uint8_t gpio_mask);
void GPIO_togglebit(GPIOdef* gpio_addr, uint8_t gpio_mask);

// uzupelnic biblioteke o funkcje
// void GPIO_readbit(GPIOdef* gpio_addr, uint8_t gpio_bit);

#endif//GPIO_PORT_AVR_H_
