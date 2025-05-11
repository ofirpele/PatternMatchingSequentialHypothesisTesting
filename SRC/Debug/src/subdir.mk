################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GLOBALS.cpp \
../src/HSMain.cpp 

OBJS += \
./src/GLOBALS.o \
./src/HSMain.o 

CPP_DEPS += \
./src/GLOBALS.d \
./src/HSMain.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_GLIBCXX_DEBUG -UNDEBUG -I/cs/phd/ofirpele/vis/src -I../src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


