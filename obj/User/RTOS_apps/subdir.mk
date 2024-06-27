################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/RTOS_apps/IMU_handle.c \
../User/RTOS_apps/Print_status.c \
../User/RTOS_apps/control_handle.c \
../User/RTOS_apps/soft_stast.c 

OBJS += \
./User/RTOS_apps/IMU_handle.o \
./User/RTOS_apps/Print_status.o \
./User/RTOS_apps/control_handle.o \
./User/RTOS_apps/soft_stast.o 

C_DEPS += \
./User/RTOS_apps/IMU_handle.d \
./User/RTOS_apps/Print_status.d \
./User/RTOS_apps/control_handle.d \
./User/RTOS_apps/soft_stast.d 


# Each subdirectory must supply rules for building sources it contributes
User/RTOS_apps/%.o: ../User/RTOS_apps/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Debug" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\User\RTOS_apps" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files\apps\inc" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Debug" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files\drivers" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Core" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\User" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Peripheral\inc" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files\drivers" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files\apps" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\General_Files\eMPL" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Core" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\User" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\Peripheral\inc" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\include" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\Common" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\86155\Desktop\ËÄÐýÒí\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

