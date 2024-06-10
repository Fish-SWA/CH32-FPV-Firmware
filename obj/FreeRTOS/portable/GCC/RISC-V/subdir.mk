################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/port.c 

S_UPPER_SRCS += \
../FreeRTOS/portable/GCC/RISC-V/portASM.S 

OBJS += \
./FreeRTOS/portable/GCC/RISC-V/port.o \
./FreeRTOS/portable/GCC/RISC-V/portASM.o 

S_UPPER_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/portASM.d 

C_DEPS += \
./FreeRTOS/portable/GCC/RISC-V/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Debug" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\drivers" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\apps" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\General_Files\eMPL" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Core" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\User" -I"E:\Download\CH32V307EVT\EVT\EXAM\SRC\Peripheral\inc" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\include" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\Common" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\MemMang" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
FreeRTOS/portable/GCC/RISC-V/%.o: ../FreeRTOS/portable/GCC/RISC-V/%.S
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -x assembler-with-cpp -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\Startup" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\include" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\Common" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\Download\CH32V307EVT\EVT\EXAM\FreeRTOS\FreeRTOS_Core\FreeRTOS\portable\MemMang" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

