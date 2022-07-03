/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "gpio.h"

void ISR_OF_EXTI0(void);
void ISR_OF_EXTI1(void);

int state = 0;
int main(void)
{
	/// Set pin 0,1 in B to input in B
	GPIO_Init(GPIOB,0,0,1);
	GPIO_Init(GPIOB,1,0,1);
	/// Set pin 0,1 to pull up
	GPIO_PUPDR(GPIOB,0,1);
	GPIO_PUPDR(GPIOB,1,1);

	//Set pin 0 , 1, 2 to output in A
	GPIO_Init(GPIOA,0,1,0);
	GPIO_Init(GPIOA,1,1,0);
	GPIO_Init(GPIOA,2,1,0);
	GPIO_Init(GPIOA,3,1,0);

	// Enable clock access to sysconf
	RCC->APB2ENR|=(1u<<14);




 	// Set Selection lines of EXTI0 bit 0
	SYSCFG->EXTICR[0] |=(1u<<0);
	SYSCFG->EXTICR[0] &=~(1u<<1);
	SYSCFG->EXTICR[0] &=~(1u<<2);
	SYSCFG->EXTICR[0] &=~(1u<<3);





	// Set Selection lines of EXTI0 bit 1
	SYSCFG->EXTICR[0] |=(1u<<4);
	SYSCFG->EXTICR[0] &=~(1u<<5);
	SYSCFG->EXTICR[0] &=~(1u<<6);
	SYSCFG->EXTICR[0] &=~(1u<<7);



	// Configure the mask bit of exti0 bit 0
	EXTI->IMR |=(1u<<0);

	// Configure the mask bit of exti0 bit 1
	EXTI->IMR |=(1u<<1);


	// Configure the Trigger  as falling trigger
	EXTI->FTSR |=(1u<<0);
	// Configure the Trigger  as falling trigger
	EXTI->FTSR |=(1u<<1);

	// enable EXTI0 interrupt from NVIC
	NVIC->ISER[0]|=(1u<<6);
	NVIC->ISER[0]|=(1u<<7);



	while(1)
	{
		state %=10;
		switch (state) {
		case 0:
			GPIO_Write(GPIOA, 0, 0);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 1:
			GPIO_Write(GPIOA, 0, 1);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 2:
			GPIO_Write(GPIOA, 0, 0);
			GPIO_Write(GPIOA, 1, 1);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 3:
			GPIO_Write(GPIOA, 0, 1);
			GPIO_Write(GPIOA, 1, 1);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 4:
			GPIO_Write(GPIOA, 0, 0);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 1);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 5:
			GPIO_Write(GPIOA, 0, 1);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 1);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 6:
			GPIO_Write(GPIOA, 0, 0);
			GPIO_Write(GPIOA, 1, 1);
			GPIO_Write(GPIOA, 2, 1);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 7:
			GPIO_Write(GPIOA, 0, 1);
			GPIO_Write(GPIOA, 1, 1);
			GPIO_Write(GPIOA, 2, 1);
			GPIO_Write(GPIOA, 3, 0);
			break;
		case 8:
			GPIO_Write(GPIOA, 0, 0);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 1);
			break;
		case 9:
			GPIO_Write(GPIOA, 0, 1);
			GPIO_Write(GPIOA, 1, 0);
			GPIO_Write(GPIOA, 2, 0);
			GPIO_Write(GPIOA, 3, 1);
			break;
		}
	}


}



void ISR_OF_EXTI0(void)
{
	state++;
}
void EXTI0_IRQHandler(void){
	ISR_OF_EXTI0();
}

void ISR_OF_EXTI1(void)
{
	if(state>0){
		state--;
	}
}
void EXTI1_IRQHandler(void){
	ISR_OF_EXTI1();
}


