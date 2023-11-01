################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SEVSEG/SEVSEG_program.c 

OBJS += \
./HAL/SEVSEG/SEVSEG_program.o 

C_DEPS += \
./HAL/SEVSEG/SEVSEG_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SEVSEG/%.o: ../HAL/SEVSEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


