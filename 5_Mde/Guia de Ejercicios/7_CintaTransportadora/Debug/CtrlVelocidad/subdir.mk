################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CtrlVelocidad/CtrlVelocidadMde.c \
../CtrlVelocidad/CtrlVelocidadMde_func.c 

OBJS += \
./CtrlVelocidad/CtrlVelocidadMde.o \
./CtrlVelocidad/CtrlVelocidadMde_func.o 

C_DEPS += \
./CtrlVelocidad/CtrlVelocidadMde.d \
./CtrlVelocidad/CtrlVelocidadMde_func.d 


# Each subdirectory must supply rules for building sources it contributes
CtrlVelocidad/%.o: ../CtrlVelocidad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/5_Mde/Guia de Ejercicios/7_CintaTransportadora/CtrlVelocidad" -I"/home/d_lugano/infoII/5_Mde/Guia de Ejercicios/7_CintaTransportadora/Encoder" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

