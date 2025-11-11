#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdint.h>

#define ENCODER_PIN_OFF 0
#define ENCODER_PIN_ON  1

#define state_0		0x00
#define state_R1    0x01
#define state_R2	0x02
#define state_R3	0x03
#define state_R4	0x04
#define state_L1	0x10
#define state_L2	0x20
#define state_L3	0x30
#define state_L4	0x40

void encoder_sm(void);
int8_t encoder_read(void);

uint8_t encoder_read_L(void) __attribute__((weak));
uint8_t encoder_read_R(void) __attribute__((weak));

#endif /* ENCODER_H_ */