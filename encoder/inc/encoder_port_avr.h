#ifndef ENCODER_PORT_AVR_H_
#define ENCODER_PORT_AVR_H_

#include <stdint.h>
#include "gpio_port_avr.h"
#include "systimer_port_avr.h"
#include "encoder.h"


void encoder_port_avr_init(GPIOdef* enc_gpio_addr, uint8_t enc_pin_r, uint8_t enc_pin_l);


#endif /* ENCODER_PORT_AVR_H_ */