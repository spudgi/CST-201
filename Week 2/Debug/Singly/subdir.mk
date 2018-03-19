################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Singly/AppendNodeSGY.cpp \
../Singly/InsertNodeSGY.cpp \
../Singly/RemoveNodeSGY.cpp \
../Singly/ReverseListSGY.cpp \
../Singly/singlyLinkedSGY.cpp 

OBJS += \
./Singly/AppendNodeSGY.o \
./Singly/InsertNodeSGY.o \
./Singly/RemoveNodeSGY.o \
./Singly/ReverseListSGY.o \
./Singly/singlyLinkedSGY.o 

CPP_DEPS += \
./Singly/AppendNodeSGY.d \
./Singly/InsertNodeSGY.d \
./Singly/RemoveNodeSGY.d \
./Singly/ReverseListSGY.d \
./Singly/singlyLinkedSGY.d 


# Each subdirectory must supply rules for building sources it contributes
Singly/%.o: ../Singly/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


