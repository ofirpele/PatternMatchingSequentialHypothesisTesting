################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Test_src/TestMain.cpp \
../Test_src/Test_DiffAbs_IsSimilar_uchar.cpp \
../Test_src/Test_ExactFastMatcher.cpp \
../Test_src/Test_MakePairsMask.cpp \
../Test_src/Test_MasksMakers.cpp \
../Test_src/Test_PairsGt_IsSimilar_uchar.cpp \
../Test_src/Test_SeqFastMatcher.cpp 

OBJS += \
./Test_src/TestMain.o \
./Test_src/Test_DiffAbs_IsSimilar_uchar.o \
./Test_src/Test_ExactFastMatcher.o \
./Test_src/Test_MakePairsMask.o \
./Test_src/Test_MasksMakers.o \
./Test_src/Test_PairsGt_IsSimilar_uchar.o \
./Test_src/Test_SeqFastMatcher.o 

CPP_DEPS += \
./Test_src/TestMain.d \
./Test_src/Test_DiffAbs_IsSimilar_uchar.d \
./Test_src/Test_ExactFastMatcher.d \
./Test_src/Test_MakePairsMask.d \
./Test_src/Test_MasksMakers.d \
./Test_src/Test_PairsGt_IsSimilar_uchar.d \
./Test_src/Test_SeqFastMatcher.d 


# Each subdirectory must supply rules for building sources it contributes
Test_src/%.o: ../Test_src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -UNDEBUG -I/cs/phd/ofirpele/vis/src -I../src -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


