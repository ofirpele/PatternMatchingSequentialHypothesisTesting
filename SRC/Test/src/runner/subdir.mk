################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/runner/cmdline.c 

CPP_SRCS += \
../src/runner/MakePairsMask.cpp \
../src/runner/Runner.cpp 

OBJS += \
./src/runner/MakePairsMask.o \
./src/runner/Runner.o \
./src/runner/cmdline.o 

C_DEPS += \
./src/runner/cmdline.d 

CPP_DEPS += \
./src/runner/MakePairsMask.d \
./src/runner/Runner.d 


# Each subdirectory must supply rules for building sources it contributes
src/runner/%.o: ../src/runner/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -UNDEBUG -I/cs/phd/ofirpele/vis/src -I../src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/runner/%.o: ../src/runner/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


