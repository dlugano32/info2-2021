################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplicacion/Registros.c \
../Aplicacion/cr_startup_lpc84x.c 

OBJS += \
./Aplicacion/Registros.o \
./Aplicacion/cr_startup_lpc84x.o 

C_DEPS += \
./Aplicacion/Registros.d \
./Aplicacion/cr_startup_lpc84x.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/6_LPC845/Registros2/Registros/Funciones" -I"/home/d_lugano/infoII/6_LPC845/Registros2/Registros/Aplicacion" -I"/home/d_lugano/infoII/6_LPC845/Registros2/Registros/Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


