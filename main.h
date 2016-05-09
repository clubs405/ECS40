// Program: main.h
//
// Author: Sean Davis
//
// Modified by: Bryan Ngo and Mat Magno
//
// Inputs: None
// Outputs: None
//
// Purpose: prototype the address, fetch, decode, and execute functions. 
// 	Also enumarates eax, ebp, esp, and eip

#include "registers.h"
#include "reader.h"
#include "instruction.h"
#include "decoder.h"

enum {eax, ebp, esp, eip};
int* address(Registers *registers, char *ptr, int memory[]);
int* fetch(Reader *reader, Instruction *ins, Registers *registers);
int* d(Instruction *ins, Decoder *decoder, Registers *registers, int memory[]);
int* execute(Decoder *decoder, Registers *registers, int memory[]);
