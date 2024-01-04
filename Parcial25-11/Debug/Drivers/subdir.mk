################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_IntExt.c \
../Drivers/DR_Sensor.c \
../Drivers/DR_Tecla.c \
../Drivers/DR_Timer.c \
../Drivers/DR_USART.c 

OBJS += \
./Drivers/DR_IntExt.o \
./Drivers/DR_Sensor.o \
./Drivers/DR_Tecla.o \
./Drivers/DR_Timer.o \
./Drivers/DR_USART.o 

C_DEPS += \
./Drivers/DR_IntExt.d \
./Drivers/DR_Sensor.d \
./Drivers/DR_Tecla.d \
./Drivers/DR_Timer.d \
./Drivers/DR_USART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/Parcial25-11/Drivers" -I"/home/d_lugano/infoII/Parcial25-11/Primitivas" -I"/home/d_lugano/infoII/Parcial25-11/src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


