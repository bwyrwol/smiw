
#include <stdint.h>

#include <stm32f1xx.h>

int main(void)
{

  while(1)
  {

  }

}

/*
#include <stm32f1xx.h>

int main(void)
{
  RCC->APB2ENR  = RCC_APB2ENR_IOPEEN;
  RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

  GPIOE->CRH |= GPIO_CRH_MODE14_1;
  GPIOE->CRH &= ~GPIO_CRH_CNF14_0;

  TIM1->PSC = 999;              // prescaler
  TIM1->ARR = 3999;             // przeladowanie licznika
  TIM1->DIER = TIM_DIER_UIE;    // wywolanie przerwania przy przeladowaniu
  TIM1->CR1 = TIM_CR1_CEN;      // odblokowanie licznika

  NVIC_EnableIRQ(TIM1_UP_IRQn); // odblokowanie przerwania od licznika

  while(1);
}

void TIM1_UP_IRQHandler(void)
{
    if (TIM1->SR & TIM_SR_UIF)
    {
      TIM1->SR = ~TIM_SR_UIF;
      GPIOE->ODR ^= GPIO_ODR_ODR14;
    }
}
*/

/*
#include <stm32f1xx.h>
#include <stm32f1xx_hal_gpio.h>

int main(void)
{
  __HAL_RCC_GPIOE_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStuct;
    GPIO_InitStuct.Pin   = GPIO_PIN_14;
    GPIO_InitStuct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStuct.Mode  = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStuct.Pull  = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStuct);

  while(1)
  {
	  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
	  for (volatile uint32_t d = 0; d < 50000; d++) {};
  }
}
*/
