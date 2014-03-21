################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../sources/TFC/TFC.c" \
"../sources/TFC/TFC_ADC.c" \
"../sources/TFC/TFC_ARM_SysTick.c" \
"../sources/TFC/TFC_BoardSupport.c" \
"../sources/TFC/TFC_CrystalClock.c" \
"../sources/TFC/TFC_LineScanCamera.c" \
"../sources/TFC/TFC_Motor.c" \
"../sources/TFC/TFC_Queue.c" \
"../sources/TFC/TFC_Servo.c" \
"../sources/TFC/TFC_Terminal.c" \
"../sources/TFC/TFC_UART.c" \
"../sources/TFC/TFC_arm_cm0.c" \

C_SRCS += \
../sources/TFC/TFC.c \
../sources/TFC/TFC_ADC.c \
../sources/TFC/TFC_ARM_SysTick.c \
../sources/TFC/TFC_BoardSupport.c \
../sources/TFC/TFC_CrystalClock.c \
../sources/TFC/TFC_LineScanCamera.c \
../sources/TFC/TFC_Motor.c \
../sources/TFC/TFC_Queue.c \
../sources/TFC/TFC_Servo.c \
../sources/TFC/TFC_Terminal.c \
../sources/TFC/TFC_UART.c \
../sources/TFC/TFC_arm_cm0.c \

OBJS += \
./sources/TFC/TFC.o \
./sources/TFC/TFC_ADC.o \
./sources/TFC/TFC_ARM_SysTick.o \
./sources/TFC/TFC_BoardSupport.o \
./sources/TFC/TFC_CrystalClock.o \
./sources/TFC/TFC_LineScanCamera.o \
./sources/TFC/TFC_Motor.o \
./sources/TFC/TFC_Queue.o \
./sources/TFC/TFC_Servo.o \
./sources/TFC/TFC_Terminal.o \
./sources/TFC/TFC_UART.o \
./sources/TFC/TFC_arm_cm0.o \

C_DEPS += \
./sources/TFC/TFC.d \
./sources/TFC/TFC_ADC.d \
./sources/TFC/TFC_ARM_SysTick.d \
./sources/TFC/TFC_BoardSupport.d \
./sources/TFC/TFC_CrystalClock.d \
./sources/TFC/TFC_LineScanCamera.d \
./sources/TFC/TFC_Motor.d \
./sources/TFC/TFC_Queue.d \
./sources/TFC/TFC_Servo.d \
./sources/TFC/TFC_Terminal.d \
./sources/TFC/TFC_UART.d \
./sources/TFC/TFC_arm_cm0.d \

OBJS_QUOTED += \
"./sources/TFC/TFC.o" \
"./sources/TFC/TFC_ADC.o" \
"./sources/TFC/TFC_ARM_SysTick.o" \
"./sources/TFC/TFC_BoardSupport.o" \
"./sources/TFC/TFC_CrystalClock.o" \
"./sources/TFC/TFC_LineScanCamera.o" \
"./sources/TFC/TFC_Motor.o" \
"./sources/TFC/TFC_Queue.o" \
"./sources/TFC/TFC_Servo.o" \
"./sources/TFC/TFC_Terminal.o" \
"./sources/TFC/TFC_UART.o" \
"./sources/TFC/TFC_arm_cm0.o" \

C_DEPS_QUOTED += \
"./sources/TFC/TFC.d" \
"./sources/TFC/TFC_ADC.d" \
"./sources/TFC/TFC_ARM_SysTick.d" \
"./sources/TFC/TFC_BoardSupport.d" \
"./sources/TFC/TFC_CrystalClock.d" \
"./sources/TFC/TFC_LineScanCamera.d" \
"./sources/TFC/TFC_Motor.d" \
"./sources/TFC/TFC_Queue.d" \
"./sources/TFC/TFC_Servo.d" \
"./sources/TFC/TFC_Terminal.d" \
"./sources/TFC/TFC_UART.d" \
"./sources/TFC/TFC_arm_cm0.d" \

OBJS_OS_FORMAT += \
./sources/TFC/TFC.o \
./sources/TFC/TFC_ADC.o \
./sources/TFC/TFC_ARM_SysTick.o \
./sources/TFC/TFC_BoardSupport.o \
./sources/TFC/TFC_CrystalClock.o \
./sources/TFC/TFC_LineScanCamera.o \
./sources/TFC/TFC_Motor.o \
./sources/TFC/TFC_Queue.o \
./sources/TFC/TFC_Servo.o \
./sources/TFC/TFC_Terminal.o \
./sources/TFC/TFC_UART.o \
./sources/TFC/TFC_arm_cm0.o \


# Each subdirectory must supply rules for building sources it contributes
sources/TFC/TFC.o: ../sources/TFC/TFC.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_ADC.o: ../sources/TFC/TFC_ADC.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_ADC.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_ADC.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_ARM_SysTick.o: ../sources/TFC/TFC_ARM_SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_ARM_SysTick.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_ARM_SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_BoardSupport.o: ../sources/TFC/TFC_BoardSupport.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_BoardSupport.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_BoardSupport.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_CrystalClock.o: ../sources/TFC/TFC_CrystalClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_CrystalClock.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_CrystalClock.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_LineScanCamera.o: ../sources/TFC/TFC_LineScanCamera.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_LineScanCamera.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_LineScanCamera.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_Motor.o: ../sources/TFC/TFC_Motor.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_Motor.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_Motor.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_Queue.o: ../sources/TFC/TFC_Queue.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_Queue.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_Queue.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_Servo.o: ../sources/TFC/TFC_Servo.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_Servo.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_Servo.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_Terminal.o: ../sources/TFC/TFC_Terminal.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_Terminal.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_Terminal.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_UART.o: ../sources/TFC/TFC_UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_UART.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_UART.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/TFC/TFC_arm_cm0.o: ../sources/TFC/TFC_arm_cm0.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/TFC/TFC_arm_cm0.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/TFC/TFC_arm_cm0.o"
	@echo 'Finished building: $<'
	@echo ' '


