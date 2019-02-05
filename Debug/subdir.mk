################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Collection.cpp \
../FiveOrMore.cpp \
../FiveOrMoreVar.cpp \
../InterfacePlateau.cpp \
../Othello.cpp \
../Plateau.cpp \
../Puissance4.cpp \
../Puissance4var.cpp \
../StackTest.cpp \
../main.cpp 

OBJS += \
./Collection.o \
./FiveOrMore.o \
./FiveOrMoreVar.o \
./InterfacePlateau.o \
./Othello.o \
./Plateau.o \
./Puissance4.o \
./Puissance4var.o \
./StackTest.o \
./main.o 

CPP_DEPS += \
./Collection.d \
./FiveOrMore.d \
./FiveOrMoreVar.d \
./InterfacePlateau.d \
./Othello.d \
./Plateau.d \
./Puissance4.d \
./Puissance4var.d \
./StackTest.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


