#include<stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"


int main(void)
{
	KeyPad_INIT();
	while(1)
	{
		for(int i =0 ; i<50000;i++){}
		KeyPad_MANAGE();

	}

}
