// Program 1 for ECS40 W16 Sean Davis
//
// Written by: Bryan Ngo and Mat Magno
//
// Program: decoder.h
//
// Purpose: Create a structure that holds opcode[20], and two int*; operand1 and operand2
//       Provide a prototype for decoder function
//

#ifndef DecoderH
#define DecoderH
#include "decoder.h"
#include "registers.h"
typedef struct
{
  char opcode[20];
  int *operand1;
  int *operand2;
}Decoder;

void addl(int *op1, int *op2, Registers *registers);
void pushl(int *op1, Registers *registers, int memory[]);
void movl(int *op1, int *op2);
void subl(int *op1, int *op2, Registers *registers);
void ret(Registers *registers, int memory[]);
void andl(int *op1, int *op2, Registers *registers, int memory[]);
void leave(Registers *registers, int memory[]);

#endif















