// Program 1 for ECS40 W16 Sean Davis
//
// Written by: Bryan Ngo and Mat Magno
//
// Program: decoder.c 
//
// Purpose: manipulate stack values  
//
// Input: Operand(s) and/or structures and/or memory
// Output: None 
//
// Sample line to decode: 
//   
//  movl %esp, %ebp eip: 108 eax:  22 ebp:  992 esp: 960  
//   ^     ^     ^
// opcode  |     |
//      operand1 |
//             operand2
//
//

#include <stdio.h>
#include "decoder.h"
#include "registers.h"
#include "main.h"

void addl(int *op1, int *op2, Registers *registers)
{
  *op2 = *op1 + *op2;
  registers->regs[eax] = *op2; 
}// Adds operand1 with operand2 and puts result in operand2


void andl(int *op1, int *op2, Registers *registers, int memory[])
{
  *op2 = *op1 & *op2;
  registers->regs[esp] = *op2;
  memory[registers->regs[esp]] = *op2;
}// Bitwise ANDs operand1 with operand2, and puts result in operand2


void leave(Registers *registers, int memory[])
{
  registers->regs[esp] = registers->regs[ebp];
  memory[registers->regs[ebp]] = memory[registers->regs[esp]];
  registers->regs[esp] = registers->regs[esp] + 4;
}//Copy val in ebp->esp, copy value in memory[esp]->ebp, esp+4


void movl(int *op1, int *op2)
{
  *op2 = *op1;
}// Copies info from operand1 into operand2


void pushl(int *op1, Registers *registers, int memory[])
{
  registers->regs[esp] = registers->regs[esp] - 4;
  memory[registers->regs[esp]] = *op1;
}// Subtracts 4 from esp, places op1 info @ location specified by the esp


void ret(Registers *registers, int memory[])
{
  registers->regs[eip] = memory[registers->regs[esp]];
  registers->regs[esp] = registers->regs[esp] + 4;
}// Copies value in stack specified by esp to the eip and adds four to esp


void subl(int *op1, int *op2, Registers *registers)
{
  registers->regs[esp] = *op2;
  *op2 = *op2 - *op1;
}// Subtracts op1 from op2, and puts result in op2




