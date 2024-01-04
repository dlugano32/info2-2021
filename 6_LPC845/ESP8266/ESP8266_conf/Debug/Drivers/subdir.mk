################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_ESP8266.c \
../Drivers/DR_Init.c \
../Drivers/DR_UART.c \
../Drivers/DR_teclado.c \
../Drivers/GPIO.c \
../Drivers/Systick.c 

OBJS += \
./Drivers/DR_ESP8266.o \
./Drivers/DR_Init.o \
./Drivers/DR_UART.o \
./Drivers/DR_teclado.o \
./Drivers/GPIO.o \
./Drivers/Systick.o 

C_DEPS += \
./Drivers/DR_ESP8266.d \
./Drivers/DR_Init.d \
./Drivers/DR_UART.d \
./Drivers/DR_teclado.d \
./Drivers/GPIO.d \
./Drivers/Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/6_LPC845/ESP8266/ESP8266_conf/App" -I"/home/d_lugano/infoII/6_LPC845/ESP8266/ESP8266_conf/Drivers" -I"/home/d_lugano/infoII/6_LPC845/ESP8266/ESP8266_conf/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


