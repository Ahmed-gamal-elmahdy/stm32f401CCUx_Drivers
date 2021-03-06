/*
 * gpio.h
 *
 *  Created on: Apr 30, 2022
 *      Author: moham
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);
void GPIO_PUPDR(GPIO_TypeDef * GPIOx,char pin,char dir);

#endif /* INCLUDE_GPIO_H_ */
