#include "stm32f7xx.h"
#include "gpio.h"
#include "tim.h"

int main(void)
{
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODER7_0;
		
		GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7_1;
		GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7_0;

		GPIOA->OTYPER &= ~GPIO_OTYPER_OT7;
	
    while(1) 
		{
			 GPIOA->BSRR = GPIO_BSRR_BS7;
			 TIM_Wait(1000);
			 GPIOA->BSRR = GPIO_BSRR_BR7;
			 TIM_Wait(1000);				
    }
}
