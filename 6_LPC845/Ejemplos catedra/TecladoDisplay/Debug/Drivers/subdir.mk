################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_7Seg.c \
../Drivers/DR_GPIO.c \
../Drivers/DR_Init.c \
../Drivers/DR_teclado.c \
../Drivers/Systick.c 

OBJS += \
./Drivers/DR_7Seg.o \
./Drivers/DR_GPIO.o \
./Drivers/DR_Init.o \
./Drivers/DR_teclado.o \
./Drivers/Systick.o 

C_DEPS += \
./Drivers/DR_7Seg.d \
./Drivers/DR_GPIO.d \
./Drivers/DR_Init.d \
./Drivers/DR_teclado.d \
./Drivers/Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/Descargas/TecladoDisplay/Aplicacion" -I"/home/d_lugano/Descargas/TecladoDisplay/Drivers" -I"/home/d_lugano/Descargas/TecladoDisplay/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


