// Program: reader.h 
//
// Written by: Bryan Ngo and Mat Magno
//
// Input: None
// Output: None
//
// Purpose: Prototype reader.c and provide 1000 Instruction lines structs
//




#ifndef ReaderH
#define ReaderH

#include "instruction.h"

typedef struct 
{
  Instruction lines[1000];
}Reader;

int read(char* file, Reader *reader);
#endif









