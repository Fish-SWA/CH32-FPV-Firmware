################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/system.c 

OBJS += \
./General_Files/system.o 

C_DEPS += \
./General_Files/system.d 


# Each subdirectory must supply rules for building sources it contributes
General_Files/%.o: ../General_Files/%.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -I"D:\2024Ƕ��\proj\FPV_demo\Debug" -I"D:\2024Ƕ��\proj\FPV_demo\Core" -I"D:\2024Ƕ��\proj\FPV_demo\User" -I"D:\2024Ƕ��\proj\FPV_demo\Peripheral\inc" -I"D:\2024Ƕ��\proj\FPV_demo\General_Files" -I"D:\2024Ƕ��\proj\FPV_demo\General_Files\drivers" -I"D:\2024Ƕ��\proj\FPV_demo\General_Files\apps" -I"D:\2024Ƕ��\proj\FPV_demo\General_Files\eMPL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

