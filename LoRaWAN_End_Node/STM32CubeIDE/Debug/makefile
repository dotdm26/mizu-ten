################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Utilities/subdir.mk
-include Middlewares/SubGHz_Phy/subdir.mk
-include Middlewares/LoRaWAN/Utilities/subdir.mk
-include Middlewares/LoRaWAN/Mac/Region/subdir.mk
-include Middlewares/LoRaWAN/Mac/subdir.mk
-include Middlewares/LoRaWAN/LmHandler/subdir.mk
-include Middlewares/LoRaWAN/Crypto/subdir.mk
-include Drivers/STM32WLxx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Application/Target/subdir.mk
-include Application/Startup/subdir.mk
-include Application/Core/subdir.mk
-include Application/App/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := LoRaWAN_End_Node
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
LoRaWAN_End_Node.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LoRaWAN_End_Node.list \

OBJCOPY_BIN += \
LoRaWAN_End_Node.bin \


# All Target
all: main-build

# Main-build Target
main-build: LoRaWAN_End_Node.elf secondary-outputs

# Tool invocations
LoRaWAN_End_Node.elf: $(OBJS) $(USER_OBJS) C:\Users\thaid\OneDrive\Desktop\mizu-ten-main\Projects\NUCLEO-WL55JC\Applications\ (HERE)\LoRaWAN\ (HERE)\LoRaWAN_End_Node\ (HERE\ -\ E5\ Mini)\STM32CubeIDE\STM32WL55JCIX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "LoRaWAN_End_Node.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\thaid\OneDrive\Desktop\mizu-ten-main\Projects\NUCLEO-WL55JC\Applications (HERE)\LoRaWAN (HERE)\LoRaWAN_End_Node (HERE - E5 Mini)\STM32CubeIDE\STM32WL55JCIX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LoRaWAN_End_Node.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LoRaWAN_End_Node.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LoRaWAN_End_Node.list"
	@echo 'Finished building: $@'
	@echo ' '

LoRaWAN_End_Node.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LoRaWAN_End_Node.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) LoRaWAN_End_Node.bin LoRaWAN_End_Node.elf LoRaWAN_End_Node.list default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
