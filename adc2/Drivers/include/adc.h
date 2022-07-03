

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

enum resolution {res12,res10,res8,res6};
enum convmode {single,cont};

#define USE_POLLING 1

typedef struct mystruct{
	enum resolution res;
	enum convmode conv;
	int vre;
}ADCConfigType;

void ADC_Init(ADCConfigType* ConfigParamPtr);
void ADC_StartConv();
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
unsigned char ADC_ReadData(int* DataPtr);
#endif /* INCLUDE_ADC_H_ */
