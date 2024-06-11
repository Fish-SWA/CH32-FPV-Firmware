################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/eMPL/inv_mpu.c \
../General_Files/eMPL/inv_mpu_dmp_motion_driver.c 

OBJS += \
./General_Files/eMPL/inv_mpu.o \
./General_Files/eMPL/inv_mpu_dmp_motion_driver.o 

C_DEPS += \
./General_Files/eMPL/inv_mpu.d \
./General_Files/eMPL/inv_mpu_dmp_motion_driver.d 


# Each subdirectory must supply rules for building sources it contributes
General_Files/eMPL/%.o: ../General_Files/eMPL/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Debug" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\User\RTOS_apps" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files\apps\inc" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Debug" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files\drivers" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Core" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\User" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Peripheral\inc" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files\drivers" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files\apps" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\General_Files\eMPL" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Core" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\User" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\Peripheral\inc" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS\include" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS\portable\Common" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\Document\GKD\CH32-FPV\CH32-FPV-Firmware\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

