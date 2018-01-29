################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Motor/Motor.c 

OBJS += \
./src/Motor/Motor.o 

C_DEPS += \
./src/Motor/Motor.d 


# Each subdirectory must supply rules for building sources it contributes
src/Motor/%.o: ../src/Motor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -DSTM32F40XX -DSTM32F40_41xxx -DUSE_STDPERIPH_DRIVER -I"/home/simon/Design_3/Motor_Controller_SW4STM_Workspace/Motor_Controller/StdPeriph_Driver/inc" -I"/home/simon/Design_3/Motor_Controller_SW4STM_Workspace/Motor_Controller/inc" -I"/home/simon/Design_3/Motor_Controller_SW4STM_Workspace/Motor_Controller/CMSIS/device" -I"/home/simon/Design_3/Motor_Controller_SW4STM_Workspace/Motor_Controller/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


