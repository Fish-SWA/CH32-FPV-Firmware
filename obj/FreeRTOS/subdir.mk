################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/croutine.c \
../FreeRTOS/event_groups.c \
../FreeRTOS/list.c \
../FreeRTOS/queue.c \
../FreeRTOS/stream_buffer.c \
../FreeRTOS/tasks.c \
../FreeRTOS/timers.c 

OBJS += \
./FreeRTOS/croutine.o \
./FreeRTOS/event_groups.o \
./FreeRTOS/list.o \
./FreeRTOS/queue.o \
./FreeRTOS/stream_buffer.o \
./FreeRTOS/tasks.o \
./FreeRTOS/timers.o 

C_DEPS += \
./FreeRTOS/croutine.d \
./FreeRTOS/event_groups.d \
./FreeRTOS/list.d \
./FreeRTOS/queue.d \
./FreeRTOS/stream_buffer.d \
./FreeRTOS/tasks.d \
./FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/%.o: ../FreeRTOS/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Debug" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\User\RTOS_apps" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files\apps\inc" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Debug" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files\drivers" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Core" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\User" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Peripheral\inc" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files\drivers" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files\apps" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\General_Files\eMPL" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Core" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\User" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\Peripheral\inc" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\include" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\Common" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\86155\Desktop\������\FPV-Master-git\CH32-FPV-Firmware\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

