################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_Init.c \
../Drivers/DR_Teclado.c \
../Drivers/GPIO.c \
../Drivers/Systick.c 

OBJS += \
./Drivers/DR_Init.o \
./Drivers/DR_Teclado.o \
./Drivers/GPIO.o \
./Drivers/Systick.o 

C_DEPS += \
./Drivers/DR_Init.d \
./Drivers/DR_Teclado.d \
./Drivers/GPIO.d \
./Drivers/Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/TPLs/TPL3/EJ1_2_3/Aplicacion" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ1_2_3/Drivers" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ1_2_3/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


