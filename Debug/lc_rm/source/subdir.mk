################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lc_rm/source/bsp_can.c \
../lc_rm/source/bsp_usart.c \
../lc_rm/source/pid.c \
../lc_rm/source/robomaster_vcan.c 

OBJS += \
./lc_rm/source/bsp_can.o \
./lc_rm/source/bsp_usart.o \
./lc_rm/source/pid.o \
./lc_rm/source/robomaster_vcan.o 

C_DEPS += \
./lc_rm/source/bsp_can.d \
./lc_rm/source/bsp_usart.d \
./lc_rm/source/pid.d \
./lc_rm/source/robomaster_vcan.d 


# Each subdirectory must supply rules for building sources it contributes
lc_rm/source/bsp_can.o: ../lc_rm/source/bsp_can.c lc_rm/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lc_rm/source/bsp_can.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
lc_rm/source/bsp_usart.o: ../lc_rm/source/bsp_usart.c lc_rm/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lc_rm/source/bsp_usart.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
lc_rm/source/pid.o: ../lc_rm/source/pid.c lc_rm/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lc_rm/source/pid.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
lc_rm/source/robomaster_vcan.o: ../lc_rm/source/robomaster_vcan.c lc_rm/source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"lc_rm/source/robomaster_vcan.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

