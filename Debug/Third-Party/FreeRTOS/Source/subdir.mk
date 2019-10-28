################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-Party/FreeRTOS/Source/croutine.c \
../Third-Party/FreeRTOS/Source/event_groups.c \
../Third-Party/FreeRTOS/Source/list.c \
../Third-Party/FreeRTOS/Source/queue.c \
../Third-Party/FreeRTOS/Source/stream_buffer.c \
../Third-Party/FreeRTOS/Source/tasks.c \
../Third-Party/FreeRTOS/Source/timers.c 

OBJS += \
./Third-Party/FreeRTOS/Source/croutine.o \
./Third-Party/FreeRTOS/Source/event_groups.o \
./Third-Party/FreeRTOS/Source/list.o \
./Third-Party/FreeRTOS/Source/queue.o \
./Third-Party/FreeRTOS/Source/stream_buffer.o \
./Third-Party/FreeRTOS/Source/tasks.o \
./Third-Party/FreeRTOS/Source/timers.o 

C_DEPS += \
./Third-Party/FreeRTOS/Source/croutine.d \
./Third-Party/FreeRTOS/Source/event_groups.d \
./Third-Party/FreeRTOS/Source/list.d \
./Third-Party/FreeRTOS/Source/queue.d \
./Third-Party/FreeRTOS/Source/stream_buffer.d \
./Third-Party/FreeRTOS/Source/tasks.d \
./Third-Party/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third-Party/FreeRTOS/Source/%.o: ../Third-Party/FreeRTOS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411RETx -DNUCLEO_F411RE -DDEBUG -DSTM32F411xE -DUSE_STDPERIPH_DRIVER -I"C:/Users/rawww/workspace/stdperiph_f4/StdPeriph_Driver/inc" -I"C:/Users/rawww/workspace/stdperiph_f4/Config" -I"C:/Users/rawww/workspace/stdperiph_f4/Third-Party/FreeRTOS/Source/include" -I"C:/Users/rawww/workspace/stdperiph_f4/Third-Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/rawww/workspace/stdperiph_f4/inc" -I"C:/Users/rawww/workspace/stdperiph_f4/CMSIS/device" -I"C:/Users/rawww/workspace/stdperiph_f4/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


