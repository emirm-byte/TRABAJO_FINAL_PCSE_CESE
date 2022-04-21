################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/APDS_9930/src/driver.c \
../Drivers/APDS_9930/src/port.c 

OBJS += \
./Drivers/APDS_9930/src/driver.o \
./Drivers/APDS_9930/src/port.o 

C_DEPS += \
./Drivers/APDS_9930/src/driver.d \
./Drivers/APDS_9930/src/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/APDS_9930/src/%.o Drivers/APDS_9930/src/%.su: ../Drivers/APDS_9930/src/%.c Drivers/APDS_9930/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/emiliano/STM32CubeIDE/workspace_1.9.0/I2C_TESt/Drivers/APDS_9930" -I"/home/emiliano/STM32CubeIDE/workspace_1.9.0/I2C_TESt/Drivers/APDS_9930/src" -I"/home/emiliano/STM32CubeIDE/workspace_1.9.0/I2C_TESt/Drivers/APDS_9930/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-APDS_9930-2f-src

clean-Drivers-2f-APDS_9930-2f-src:
	-$(RM) ./Drivers/APDS_9930/src/driver.d ./Drivers/APDS_9930/src/driver.o ./Drivers/APDS_9930/src/driver.su ./Drivers/APDS_9930/src/port.d ./Drivers/APDS_9930/src/port.o ./Drivers/APDS_9930/src/port.su

.PHONY: clean-Drivers-2f-APDS_9930-2f-src

