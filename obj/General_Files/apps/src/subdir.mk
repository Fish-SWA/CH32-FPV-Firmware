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
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fsingle-precision-constant -Wunused -Wuninitialized  -g -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Debug" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Core" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\User" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\Peripheral\inc" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\drivers" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\apps" -I"E:\Document\WeChat Files\wxid_15t014nog1r512\FileStorage\File\2024-05\FPV_demo\General_Files\eMPL" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

