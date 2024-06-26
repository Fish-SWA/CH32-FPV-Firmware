################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/drivers/BMP280.c \
../General_Files/drivers/MPU6050.c \
../General_Files/drivers/MyI2C.c \
../General_Files/drivers/ST7789.c \
../General_Files/drivers/adc.c \
../General_Files/drivers/bsp_filter.c \
../General_Files/drivers/gpio.c \
../General_Files/drivers/mtf01.c \
../General_Files/drivers/pwm.c \
../General_Files/drivers/tim.c \
../General_Files/drivers/uart.c 

OBJS += \
./General_Files/drivers/BMP280.o \
./General_Files/drivers/MPU6050.o \
./General_Files/drivers/MyI2C.o \
./General_Files/drivers/ST7789.o \
./General_Files/drivers/adc.o \
./General_Files/drivers/bsp_filter.o \
./General_Files/drivers/gpio.o \
./General_Files/drivers/mtf01.o \
./General_Files/drivers/pwm.o \
./General_Files/drivers/tim.o \
./General_Files/drivers/uart.o 

C_DEPS += \
./General_Files/drivers/BMP280.d \
./General_Files/drivers/MPU6050.d \
./General_Files/drivers/MyI2C.d \
./General_Files/drivers/ST7789.d \
./General_Files/drivers/adc.d \
./General_Files/drivers/bsp_filter.d \
./General_Files/drivers/gpio.d \
./General_Files/drivers/mtf01.d \
./General_Files/drivers/pwm.d \
./General_Files/drivers/tim.d \
./General_Files/drivers/uart.d 


# Each subdirectory must supply rules for building sources it contributes
General_Files/drivers/%.o: ../General_Files/drivers/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Debug" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User\RTOS_apps" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\apps\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Debug" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\drivers" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Core" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Peripheral\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\drivers" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\apps" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\General_Files\eMPL" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Core" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\User" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\Peripheral\inc" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\include" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\Common" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\86155\Desktop\四旋翼\CH32-FPV-Firmware - 副本\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

