################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f427iihx.s 

OBJS += \
./Core/Startup/startup_stm32f427iihx.o 

S_DEPS += \
./Core/Startup/startup_stm32f427iihx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32f427iihx.o: ../Core/Startup/startup_stm32f427iihx.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Core/Startup/startup_stm32f427iihx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

