################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_ADC.c \
../Drivers/DR_Teclado.c \
../Drivers/DR_serie.c \
../Drivers/Systick.c 

OBJS += \
./Drivers/DR_ADC.o \
./Drivers/DR_Teclado.o \
./Drivers/DR_serie.o \
./Drivers/Systick.o 

C_DEPS += \
./Drivers/DR_ADC.d \
./Drivers/DR_Teclado.d \
./Drivers/DR_serie.d \
./Drivers/Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/6_LPC845/Parcial11_20/EJ4_Parcial/Drivers" -I"/home/d_lugano/infoII/6_LPC845/Parcial11_20/EJ4_Parcial/src" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


