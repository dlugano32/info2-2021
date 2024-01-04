################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/JustDanceMDE.c \
../App/MDE_funciones.c \
../App/cr_startup_lpc84x.c \
../App/crp.c \
../App/main.c 

OBJS += \
./App/JustDanceMDE.o \
./App/MDE_funciones.o \
./App/cr_startup_lpc84x.o \
./App/crp.o \
./App/main.o 

C_DEPS += \
./App/JustDanceMDE.d \
./App/MDE_funciones.d \
./App/cr_startup_lpc84x.d \
./App/crp.d \
./App/main.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o: ../App/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/TPO/TPO_V1.2/App" -I"/home/d_lugano/infoII/TPO/TPO_V1.2/Drivers" -I"/home/d_lugano/infoII/TPO/TPO_V1.2/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


