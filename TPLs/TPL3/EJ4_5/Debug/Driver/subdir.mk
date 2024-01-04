################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/DR_Init.c \
../Driver/IntExt.c \
../Driver/Systick.c \
../Driver/gpio.c 

OBJS += \
./Driver/DR_Init.o \
./Driver/IntExt.o \
./Driver/Systick.o \
./Driver/gpio.o 

C_DEPS += \
./Driver/DR_Init.d \
./Driver/IntExt.d \
./Driver/Systick.d \
./Driver/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/%.o: ../Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Aplicacion" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Driver" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


