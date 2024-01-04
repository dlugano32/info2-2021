################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplicacion/cr_startup_lpc84x.c \
../Aplicacion/crp.c \
../Aplicacion/main.c 

OBJS += \
./Aplicacion/cr_startup_lpc84x.o \
./Aplicacion/crp.o \
./Aplicacion/main.o 

C_DEPS += \
./Aplicacion/cr_startup_lpc84x.d \
./Aplicacion/crp.d \
./Aplicacion/main.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Aplicacion" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Driver" -I"/home/d_lugano/infoII/TPLs/TPL3/EJ4_5/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


