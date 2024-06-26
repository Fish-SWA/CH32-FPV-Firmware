################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../Startup/startup_ch32v30x_D8C.S 

OBJS += \
./Startup/startup_ch32v30x_D8C.o 

S_UPPER_DEPS += \
./Startup/startup_ch32v30x_D8C.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.S
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -x assembler-with-cpp -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Startup" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\include" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\Common" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

