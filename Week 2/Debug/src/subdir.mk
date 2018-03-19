################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/InsertNodeSGY.cpp \
../src/RemoveNodeSGY.cpp \
../src/singlyLinkedSGY.cpp 

OBJS += \
./src/InsertNodeSGY.o \
./src/RemoveNodeSGY.o \
./src/singlyLinkedSGY.o 

CPP_DEPS += \
./src/InsertNodeSGY.d \
./src/RemoveNodeSGY.d \
./src/singlyLinkedSGY.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


