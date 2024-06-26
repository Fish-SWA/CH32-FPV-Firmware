################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/RTOS_tasks.c \
../User/ch32v30x_it.c \
../User/main.c \
../User/system_ch32v30x.c 

OBJS += \
./User/RTOS_tasks.o \
./User/ch32v30x_it.o \
./User/main.o \
./User/system_ch32v30x.o 

C_DEPS += \
./User/RTOS_tasks.d \
./User/ch32v30x_it.d \
./User/main.d \
./User/system_ch32v30x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Debug" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User\RTOS_apps" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\apps\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Debug" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\drivers" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Core" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Peripheral\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\drivers" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\apps" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\eMPL" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Core" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Peripheral\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\include" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\Common" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

