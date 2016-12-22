################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../inorder.c \
../leaves.c \
../main.c \
../testout.c \
../treeheight.c 

OBJS += \
./inorder.o \
./leaves.o \
./main.o \
./testout.o \
./treeheight.o 

C_DEPS += \
./inorder.d \
./leaves.d \
./main.d \
./testout.d \
./treeheight.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


