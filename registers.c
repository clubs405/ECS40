// Program 1 for Sean Davis ECS40 W16
//
// Created by: Bryan Ngo and Mat Magno
//
// Program: registers.c
//
// Function of the program: Initialize register values
//

#include <stdio.h>
#include "registers.h"
#include "main.h"

void initialize(Registers *registers, int memory[])
{
  registers->regs[eip] = 100;   // 'eip' Status Control
  registers->regs[esp] = 1000;  // 'esp' Stack Pointer
  registers->regs[ebp] = 996;   // 'ebp' Base Pointer
  registers->regs[eax] = 0;     // 'eax' Gen Purpose Regs
  memory[1000] = 0;

} //Initialize registers














