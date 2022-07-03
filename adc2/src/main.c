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
#include "LCD.h"
#include "adc.h"

int data=0;
void display(void);

int main(void)
{

	for(int i=0;i<6000000;i++){}
	ADCConfigType mystruct;
	mystruct.res=res12;
	mystruct.conv=cont;

	LCD_Init();
	ADC_Init(&mystruct);
	ADC_StartConv();
	if(mystruct.conv ==cont && USE_POLLING){
		while(1)
			{
				for(int i=0;i<600000;i++){}
				LCD_ClearScreen();
				LCD_DisplayString("Temperature:");
				ADC_ReadData(&data);
				LCD_IntToStr(data);
				LCD_DisplayString("C");
			}
	}
}
void display(void){
	LCD_ClearScreen();
	LCD_DisplayString("Temperature:");
	ADC_ReadData(&data);
	LCD_IntToStr(data);
	LCD_DisplayString("C");
}
void ADC_IRQHandler (void){
	display();
}

