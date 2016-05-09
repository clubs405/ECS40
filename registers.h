// Program 1 for Sean Davis ECS40 W16
//
// Created by: Bryan Ngo and Mat Magno
// Program: registers.h
//
// Function of the program: Creates structure for the 4 registers
//   -> esp, ebp, eip, eax
//
//   esp - stack pointer
//   ebp - base pointer 
//   eax - general purpose (accumulator)
//   eip - status/control (step counter) 
//
//    and to provide prototype for register function
//

// structure for registers
#ifndef RegisterH
#define RegisterH
typedef struct
{ 
  int regs[4];
}Registers;

void initialize(Registers *registers, int* memory);
#endif 










