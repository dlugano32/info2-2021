################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include Spray/subdir.mk
-include Paila/subdir.mk
-include EntradasSalidas/subdir.mk
-include Calefa/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Recubrimiento_Pastillas.axf

# Tool invocations
Recubrimiento_Pastillas.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Recubrimiento_Pastillas.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0 -mthumb -T "Recubrimiento_Pastillas_Debug.ld" -o "Recubrimiento_Pastillas.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Recubrimiento_Pastillas.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Recubrimiento_Pastillas.axf"; # arm-none-eabi-objcopy -v -O binary "Recubrimiento_Pastillas.axf" "Recubrimiento_Pastillas.bin" ; # checksum -p LPC845 -d "Recubrimiento_Pastillas.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
