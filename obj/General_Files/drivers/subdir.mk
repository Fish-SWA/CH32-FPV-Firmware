################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../General_Files/drivers/BMP280.c \
../General_Files/drivers/MPU6050.c \
../General_Files/drivers/MyI2C.c \
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
./General_Files/drivers/adc.d \
./General_Files/drivers/bsp_filter.d \
./General_Files/drivers/gpio.d \
./General_Files/drivers/mtf01.d \
./General_Files/drivers/pwm.d \
./General_Files/drivers/tim.d \
./General_Files/drivers/uart.d 


# Each subdirectory must supply rules for building sources it contributes
General_Files/drivers/%.o: ../General_Files/drivers/%.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Debug" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Core" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\User" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Peripheral\inc" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\drivers" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\apps" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\eMPL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

