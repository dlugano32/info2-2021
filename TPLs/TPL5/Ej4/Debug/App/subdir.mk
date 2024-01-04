################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../App/aeabi_romdiv_patch.s 

C_SRCS += \
../App/cr_startup_lpc84x.c \
../App/crp.c \
../App/main.c \
../App/mtb.c 

OBJS += \
./App/aeabi_romdiv_patch.o \
./App/cr_startup_lpc84x.o \
./App/crp.o \
./App/main.o \
./App/mtb.o 

C_DEPS += \
./App/cr_startup_lpc84x.d \
./App/crp.d \
./App/main.d \
./App/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o: ../App/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -g3 -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

App/%.o: ../App/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


