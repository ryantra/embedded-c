################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
packedVsnpacked.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
packedVsnpacked.list \

OBJCOPY_BIN += \
packedVsnpacked.bin \


# All Target
all: packedVsnpacked.elf secondary-outputs

# Tool invocations
packedVsnpacked.elf: $(OBJS) $(USER_OBJS) /home/rupesh/Embedded-C/My_Workspace/target/packedVsnpacked/STM32F411RETX_FLASH.ld
	arm-none-eabi-gcc -o "packedVsnpacked.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/rupesh/Embedded-C/My_Workspace/target/packedVsnpacked/STM32F411RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="packedVsnpacked.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

packedVsnpacked.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "packedVsnpacked.list"
	@echo 'Finished building: $@'
	@echo ' '

packedVsnpacked.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "packedVsnpacked.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
