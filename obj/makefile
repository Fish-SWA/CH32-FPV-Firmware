################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include General_Files/eMPL/subdir.mk
-include General_Files/drivers/subdir.mk
-include General_Files/apps/src/subdir.mk
-include General_Files/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
FPV_demo.hex \

SECONDARY_LIST += \
FPV_demo.lst \

SECONDARY_SIZE += \
FPV_demo.siz \


# All Target
all: FPV_demo.elf secondary-outputs

# Tool invocations
FPV_demo.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -T "C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -L../ -Wl,-Map,"FPV_demo.map" --specs=nano.specs --specs=nosys.specs  -o "FPV_demo.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lprintfloat
	@	@
FPV_demo.hex: FPV_demo.elf
	@	riscv-none-embed-objcopy -O ihex "FPV_demo.elf"  "FPV_demo.hex"
	@	@
FPV_demo.lst: FPV_demo.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble "FPV_demo.elf" > "FPV_demo.lst"
	@	@
FPV_demo.siz: FPV_demo.elf
	@	riscv-none-embed-size --format=berkeley "FPV_demo.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) FPV_demo.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
