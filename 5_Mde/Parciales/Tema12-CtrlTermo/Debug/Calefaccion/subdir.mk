################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calefaccion/CalefaMde.c \
../Calefaccion/CalefaMde_func.c 

OBJS += \
./Calefaccion/CalefaMde.o \
./Calefaccion/CalefaMde_func.o 

C_DEPS += \
./Calefaccion/CalefaMde.d \
./Calefaccion/CalefaMde_func.d 


# Each subdirectory must supply rules for building sources it contributes
Calefaccion/%.o: ../Calefaccion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/5_Mde/Parciales/Tema12-CtrlTermo/BombaMde" -I"/home/d_lugano/infoII/5_Mde/Parciales/Tema12-CtrlTermo/Calefaccion" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


