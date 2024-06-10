################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/apps/src/CRC.c \
../General_Files/apps/src/CRSF.c \
../General_Files/apps/src/control.c \
../General_Files/apps/src/pid.c 

OBJS += \
./General_Files/apps/src/CRC.o \
./General_Files/apps/src/CRSF.o \
./General_Files/apps/src/control.o \
./General_Files/apps/src/pid.o 

C_DEPS += \
./General_Files/apps/src/CRC.d \
./General_Files/apps/src/CRSF.d \
./General_Files/apps/src/control.d \
./General_Files/apps/src/pid.d 


# Each subdirectory must supply rules for building sources it contributes
General_Files/apps/src/%.o: ../General_Files/apps/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\apps" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\eMPL" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\include" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\Common" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

