################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/Leds.c \
../Primitivas/PR_7seg.c \
../Primitivas/PR_Matriz.c \
../Primitivas/TImer.c \
../Primitivas/Tecla.c 

OBJS += \
./Primitivas/Leds.o \
./Primitivas/PR_7seg.o \
./Primitivas/PR_Matriz.o \
./Primitivas/TImer.o \
./Primitivas/Tecla.o 

C_DEPS += \
./Primitivas/Leds.d \
./Primitivas/PR_7seg.d \
./Primitivas/PR_Matriz.d \
./Primitivas/TImer.d \
./Primitivas/Tecla.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/TPO/TPO_v1.1/Aplicacion" -I"/home/d_lugano/infoII/TPO/TPO_v1.1/Drivers" -I"/home/d_lugano/infoII/TPO/TPO_v1.1/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


