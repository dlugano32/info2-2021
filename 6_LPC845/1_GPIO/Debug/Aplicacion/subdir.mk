################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplicacion/GPIO.c \
../Aplicacion/cr_startup_lpc84x.c \
../Aplicacion/crp.c 

OBJS += \
./Aplicacion/GPIO.o \
./Aplicacion/cr_startup_lpc84x.o \
./Aplicacion/crp.o 

C_DEPS += \
./Aplicacion/GPIO.d \
./Aplicacion/cr_startup_lpc84x.d \
./Aplicacion/crp.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/6_LPC845/GPIO/Aplicacion" -I"/home/d_lugano/infoII/6_LPC845/GPIO/Drivers" -I"/home/d_lugano/infoII/6_LPC845/GPIO/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


