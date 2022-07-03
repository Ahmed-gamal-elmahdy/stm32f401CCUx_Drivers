#include "stm32f4xx.h"
#include "keypad.h"
#include "gpio.h"

const int no_rows = 4;
const int no_cols = 3;
int rows[4]={1,2,3,4}; //fill the array
int cols[3]={5,6,7}; //fill the array

int lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

int currentvalue;


void KeyPad_INIT(void)
{

	// set input and ouput pins

		// get pins from row and set it as output
	for(int i =0;i<no_rows;i++){
		GPIO_Init(GPIOA,rows[i],1,0);

	}
		// get pins from cols and set it as input
	for(int i=0;i<no_cols;i++){
		GPIO_Init(GPIOA,cols[i],0,0);
		GPIO_PUDR(GPIOA,cols[i],0);
	}
	// Set bins for 7seg
	for(int i =0;i<4;i++){
		GPIO_Init(GPIOB,i,1,1);
	}

}

void KeyPad_MANAGE(void)
{
	for(int i =0;i<no_rows;i++){
		GPIO_Write(GPIOA,rows[i],1);
		for(int j=0;j<no_cols;j++){
			if(GPIO_Read(GPIOA,cols[j])){
				currentvalue=lookupTable[i][j];
				while(GPIO_Read(GPIOA,cols[j])){}
				KeypadCallouts_KeyPressNotificaton();
			}
		}
		GPIO_Write(GPIOA,rows[i],0);
	}
}

int KeyPad_GET_VALUE(void)
{

	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	switch (currentvalue){
	case 0:
		GPIO_Write(GPIOB, 0, 0);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 1:
		GPIO_Write(GPIOB, 0, 1);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 2:
		GPIO_Write(GPIOB, 0, 0);
		GPIO_Write(GPIOB, 1, 1);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 3:
		GPIO_Write(GPIOB, 0, 1);
		GPIO_Write(GPIOB, 1, 1);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 4:
		GPIO_Write(GPIOB, 0, 0);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 1);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 5:
		GPIO_Write(GPIOB, 0, 1);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 1);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 6:
		GPIO_Write(GPIOB, 0, 0);
		GPIO_Write(GPIOB, 1, 1);
		GPIO_Write(GPIOB, 2, 1);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 7:
		GPIO_Write(GPIOB, 0, 1);
		GPIO_Write(GPIOB, 1, 1);
		GPIO_Write(GPIOB, 2, 1);
		GPIO_Write(GPIOB, 3, 0);
		break;
	case 8:
		GPIO_Write(GPIOB, 0, 0);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 1);
		break;
	case 9:
		GPIO_Write(GPIOB, 0, 1);
		GPIO_Write(GPIOB, 1, 0);
		GPIO_Write(GPIOB, 2, 0);
		GPIO_Write(GPIOB, 3, 1);
		break;
	}

}

