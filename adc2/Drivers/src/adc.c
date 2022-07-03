/*
 * ADC.c
 *
 *  Created on: May 28, 2022
 *      Author: Gemy
 */
#include "stm32f4xx.h"
#include "gpio.h"
#include "adc.h"




void ADC_Init(ADCConfigType* ConfigParamPtr){

	//enable gpioa
	RCC->AHB1ENR |=(1u<<0);
	// pin 0 to analog mode , no pull up no pull down
	GPIOA->MODER |= (1u<<0);
	GPIOA->MODER |= (1u<<1);
	GPIOA->PUPDR &=~(1u<<0);
	GPIOA->PUPDR &=~(1u<<1);
	// Enable clock access to ADC1
	RCC->APB2ENR |=(1u<<8);
	// Enable the ADC
	ADC1->CR2 |=(1u<<0);
	//clock prescaler
	ADC->CCR &= ~ADC_CCR_ADCPRE;
	//start of conversion
	// right alignment
	ADC1->CR2 &=~(1u<<11);
	// set resolution
	/*
	 * 0--> 12bit
	 * 1--> 10bit
	 * 2--> 8bit
	 * 3--> 6bit
	 */
	switch(ConfigParamPtr->res){
	case res12:
		ADC1->CR1 &=~(1u<<24);
		ADC1->CR1 &=~(1u<<25);
		break;
	case res10:
		ADC1->CR1 |=(1u<<24);
		ADC1->CR1 &=~(1u<<25);
		break;
	case res8:
		ADC1->CR1 &=~(1u<<24);
		ADC1->CR1 |=(1u<<25);
		break;
	case res6:
		ADC1->CR1 |=(1u<<24);
		ADC1->CR1 |=(1u<<25);
		break;
	}

	// check the mode continous or single
	// and if continous set cont bit
	// set conv mode
	/*
	 * 0 single conv mode
	 * 1 Continous conv mode
	 */
	if(ConfigParamPtr->conv){
		ADC1->CR2 |= (1u<<1);
	}
	else{
		ADC1->CR2 &=~(1u<<1);
	}
	// enable  interupt if use polling =0
	if(USE_POLLING){
		ADC1->CR1 &=~(1u<<5);
	}
	else{
		//enable interrput for regular channels
		ADC1->CR1 |=(1u<<5);
		NVIC->ISER[0]|=(1u<<(18));
	}
}

void ADC_StartConv(){
	ADC1->CR2 |=(1u<<30);//set swstart bit
}


void ADC_GetConversionState(unsigned char* ConversionStatePtr){

	if((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC){
		*ConversionStatePtr = 1;
	}
	else{
		*ConversionStatePtr = 0;
	}
}
unsigned char ADC_ReadData(int* DataPtr){

	unsigned char IsConverted=0;
	ADC_GetConversionState(&IsConverted);
	if(IsConverted){
		*DataPtr = (int)((ADC1->DR/(1.5f * 4095.0f)) * 3 * 150);
		return 0;
	}
	else{
		return 1;
	}
}


