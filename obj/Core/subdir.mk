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
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\Debug" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\Core" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\User" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\Peripheral\inc" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\General_Files" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\General_Files\drivers" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\General_Files\apps" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV_demo\General_Files\eMPL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

