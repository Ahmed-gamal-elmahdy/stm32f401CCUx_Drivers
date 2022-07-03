################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/LCD.c \
../Drivers/src/adc.c \
../Drivers/src/gpio.c 

OBJS += \
./Drivers/src/LCD.o \
./Drivers/src/adc.o \
./Drivers/src/gpio.o 

C_DEPS += \
./Drivers/src/LCD.d \
./Drivers/src/adc.d \
./Drivers/src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/Gemy/workspace/adc2/Drivers/include" -I"C:/Users/Gemy/workspace/adc2/inc" -I"C:/Users/Gemy/workspace/adc2/CMSIS/device" -I"C:/Users/Gemy/workspace/adc2/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


