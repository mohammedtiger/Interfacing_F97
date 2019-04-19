################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include APPS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
F97_Interfacing.lss \

FLASH_IMAGE += \
F97_Interfacing.hex \

EEPROM_IMAGE += \
F97_Interfacing.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: F97_Interfacing.elf secondary-outputs

# Tool invocations
F97_Interfacing.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,F97_Interfacing.map -mmcu=atmega32 -o "F97_Interfacing.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

F97_Interfacing.lss: F97_Interfacing.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S F97_Interfacing.elf  >"F97_Interfacing.lss"
	@echo 'Finished building: $@'
	@echo ' '

F97_Interfacing.hex: F97_Interfacing.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex F97_Interfacing.elf  "F97_Interfacing.hex"
	@echo 'Finished building: $@'
	@echo ' '

F97_Interfacing.eep: F97_Interfacing.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex F97_Interfacing.elf  "F97_Interfacing.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: F97_Interfacing.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 F97_Interfacing.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) F97_Interfacing.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
