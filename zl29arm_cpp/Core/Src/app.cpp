/*
 * app.cpp
 *
 *  Created on: 24 lis 2026
 *      Author: BW
 */


#include "app.hpp"
#include <stdio.h>

//*************************************************************
// klasa IOPin

enum class IOState {LOW = 0, HIGH = 1};

class IOPin
{
protected:
	GPIO_TypeDef* port = 0;
	uint16_t pin = 0;

public:
	IOPin(GPIO_TypeDef* port, uint16_t pin);

	void write(IOState state);
	IOState read();
};

IOPin::IOPin(GPIO_TypeDef* port, uint16_t pin): port(port), pin(pin)
{
	HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(port, &GPIO_InitStruct);
};

void IOPin::write(IOState state)
{
	HAL_GPIO_WritePin(port, pin, (GPIO_PinState)state);
};

IOState IOPin::read()
{
	return (IOState) HAL_GPIO_ReadPin(port, pin);
};

//*************************************************************
// klasa Led

enum class LedState {Off = 0, On = 1};
enum class LedConfig {LOW = 0, HIGH = 1};

class Led: public IOPin
{
private:
	LedConfig config;

public:
	Led(GPIO_TypeDef* led_port, uint16_t led_pin, LedConfig config);
	void On();
	void Off();
	void Toggle();
};

Led::Led(GPIO_TypeDef* led_port, uint16_t led_pin, LedConfig config): IOPin(led_port, led_pin)
{
	port = led_port;
	pin = led_pin;
	this->config = config;
}

void Led::On()
{
	if (config == LedConfig::HIGH)
		write(IOState::HIGH);
	else
		write(IOState::LOW);
}

void Led::Off()
{
	if (config == LedConfig::HIGH)
		write(IOState::LOW);
	else
		write(IOState::HIGH);
}

void Led::Toggle()
{
	if (read() == IOState::HIGH)
		write(IOState::LOW);
	else
		write(IOState::HIGH);
}


//*************************************************************

void app_main(void)
{
	while(1)
	{
	}

}
