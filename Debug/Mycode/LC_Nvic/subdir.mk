################################################################################
# 自动生成的文件。不要编辑！
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mycode/LC_Nvic/lc_exit_nvic.c \
../Mycode/LC_Nvic/lc_pwm.c \
../Mycode/LC_Nvic/lc_tim_nvic.c \
../Mycode/LC_Nvic/lc_ws2812.c 

OBJS += \
./Mycode/LC_Nvic/lc_exit_nvic.o \
./Mycode/LC_Nvic/lc_pwm.o \
./Mycode/LC_Nvic/lc_tim_nvic.o \
./Mycode/LC_Nvic/lc_ws2812.o 

C_DEPS += \
./Mycode/LC_Nvic/lc_exit_nvic.d \
./Mycode/LC_Nvic/lc_pwm.d \
./Mycode/LC_Nvic/lc_tim_nvic.d \
./Mycode/LC_Nvic/lc_ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
Mycode/LC_Nvic/lc_exit_nvic.o: ../Mycode/LC_Nvic/lc_exit_nvic.c Mycode/LC_Nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mycode/LC_Nvic/lc_exit_nvic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Mycode/LC_Nvic/lc_pwm.o: ../Mycode/LC_Nvic/lc_pwm.c Mycode/LC_Nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mycode/LC_Nvic/lc_pwm.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Mycode/LC_Nvic/lc_tim_nvic.o: ../Mycode/LC_Nvic/lc_tim_nvic.c Mycode/LC_Nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mycode/LC_Nvic/lc_tim_nvic.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Mycode/LC_Nvic/lc_ws2812.o: ../Mycode/LC_Nvic/lc_ws2812.c Mycode/LC_Nvic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F427xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/GitHub/WINDWILL/Mycode/include" -I"C:/GitHub/WINDWILL/lc_rm/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Mycode/LC_Nvic/lc_ws2812.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

