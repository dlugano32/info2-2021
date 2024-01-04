################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Aplicacion/aeabi_romdiv_patch.s 

C_SRCS += \
../Aplicacion/Int_Externas.c \
../Aplicacion/cr_startup_lpc84x.c \
../Aplicacion/crp.c \
../Aplicacion/mtb.c 

OBJS += \
./Aplicacion/Int_Externas.o \
./Aplicacion/aeabi_romdiv_patch.o \
./Aplicacion/cr_startup_lpc84x.o \
./Aplicacion/crp.o \
./Aplicacion/mtb.o 

C_DEPS += \
./Aplicacion/Int_Externas.d \
./Aplicacion/cr_startup_lpc84x.d \
./Aplicacion/crp.d \
./Aplicacion/mtb.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_BUFFER_SIZE=256 -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -I"/home/d_lugano/infoII/6_LPC845/Ejemplos catedra/Int_Externas/Drivers" -I"/home/d_lugano/infoII/6_LPC845/Ejemplos catedra/Int_Externas/Primitivas" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Aplicacion/%.o: ../Aplicacion/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__USE_ROMDIVIDE -D__LPC84X__ -D__REDLIB__ -g3 -mcpu=cortex-m0 -mthumb -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


