################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../sources/main.c" \
"../sources/sa_mtb.c" \

C_SRCS += \
../sources/main.c \
../sources/sa_mtb.c \

OBJS += \
./sources/main.o \
./sources/sa_mtb.o \

C_DEPS += \
./sources/main.d \
./sources/sa_mtb.d \

OBJS_QUOTED += \
"./sources/main.o" \
"./sources/sa_mtb.o" \

C_DEPS_QUOTED += \
"./sources/main.d" \
"./sources/sa_mtb.d" \

OBJS_OS_FORMAT += \
./sources/main.o \
./sources/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
sources/main.o: ../sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/main.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

sources/sa_mtb.o: ../sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"sources/sa_mtb.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -o"sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


