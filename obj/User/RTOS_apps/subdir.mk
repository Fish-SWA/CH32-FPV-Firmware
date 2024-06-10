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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User\RTOS_apps" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\apps\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\apps" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\eMPL" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\include" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\Common" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

