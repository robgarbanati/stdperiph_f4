################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Third-Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Third-Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Third-Party/FreeRTOS/Source/subdir.mk
-include StdPeriph_Driver/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: stdperiph_f4.elf

# Tool invocations
stdperiph_f4.elf: $(OBJS) $(USER_OBJS) C:\Users\rawww\workspace\stdperiph_f4/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"C:/Users/rawww/workspace/stdperiph_f4/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "stdperiph_f4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "stdperiph_f4.elf" "stdperiph_f4.bin"
	arm-none-eabi-size "stdperiph_f4.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
