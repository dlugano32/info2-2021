################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_SensorDistancia.c \
../Primitivas/PR_TECLA.c \
../Primitivas/PR_USART.c 

OBJS += \
./Primitivas/PR_SensorDistancia.o \
./Primitivas/PR_TECLA.o \
./Primitivas/PR_USART.o 

C_DEPS += \
./Primitivas/PR_SensorDistancia.d \
./Primitivas/PR_TECLA.d \
./Primitivas/PR_USART.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/Parcial25-11/Drivers" -I"/home/d_lugano/infoII/Parcial25-11/Primitivas" -I"/home/d_lugano/infoII/Parcial25-11/src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


