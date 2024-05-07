################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -I"D:\2024嵌赛\proj\FPV_demo\Debug" -I"D:\2024嵌赛\proj\FPV_demo\Core" -I"D:\2024嵌赛\proj\FPV_demo\User" -I"D:\2024嵌赛\proj\FPV_demo\Peripheral\inc" -I"D:\2024嵌赛\proj\FPV_demo\General_Files" -I"D:\2024嵌赛\proj\FPV_demo\General_Files\drivers" -I"D:\2024嵌赛\proj\FPV_demo\General_Files\apps" -I"D:\2024嵌赛\proj\FPV_demo\General_Files\eMPL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

