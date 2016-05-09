// Author: Sean Davis
//
//
//

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int i = 0; // For looping through fetch, decode, and execute


int* address(Registers *registers, char *operand, int memory[])
{
  static int value;
  char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
  char *ptr;
  int regNum, index;

  if(operand == NULL)
    return NULL;

  if(operand[0] == '$') // immediate mode
  {
    value = atoi(&operand[1]);
    return &value;
  } // if immediate mode

  for(regNum = eax; regNum <= eip; regNum++)
    if(strstr(operand, regNames[regNum]))
      break;

  ptr = strchr(operand, '(');

  if(ptr) // some form of indirect addressing
  {
    *ptr = '\0';  // terminate operand string at first '('
    index = atoi(operand);  // will return 0 if no number there!
    return  &memory[registers->regs[regNum] + index];
  } // if ptr
  else  // direct addressing
    return &(registers->regs[regNum]);

} // address ()

int* fetch(Reader *reader, Instruction *ins, Registers *registers)
{
  while(i < 20)
  {
    if(registers->regs[eip] == reader->lines[i].address)
    {
      ins->info = (char *)malloc(strlen(reader->lines[i].info));
      strcpy(ins->info, reader->lines[i].info);  
      break;
    } // if the eip matches the correct address, store the line into instruction

    i++;
  } // Exit while loop

    registers->regs[eip] = registers->regs[eip] + 4;
        
return 0;
} // Done fetching

int* d(Instruction *ins, Decoder *decoder, Registers *registers, int memory[])
{

  char *lim;
  
  while(1)
  {  
    // Gets the operator code
    lim = strtok(ins->info, " ");
    strcpy(decoder->opcode, lim);  

    // Get operand1
    lim = strtok(NULL, " ");
    decoder->operand1 = address(registers, lim, memory);
  
    // Get operand2  (if it exists)
    lim = strtok(NULL, " ");
    decoder->operand2 = address(registers, lim, memory);  
    break;
  } // Fills the decoder struct with values
  
return 0;
} // Done decoding

// Sends respective arguments to their functions based on the opcode
int* execute(Decoder *decoder, Registers *registers, int memory[])
{

  if(!(strcmp(decoder->opcode, "addl")))
    addl(decoder->operand1, decoder->operand2, registers);

  if(!(strcmp(decoder->opcode, "andl")))
    andl(decoder->operand1, decoder->operand2, registers, memory);

  if(!(strcmp(decoder->opcode, "leave")))
    leave(registers, memory);

  if(!(strcmp(decoder->opcode, "movl")))
    movl(decoder->operand1, decoder->operand2);

  if(!(strcmp(decoder->opcode, "pushl")))
    pushl(decoder->operand1, registers, memory);

  if(!(strcmp(decoder->opcode, "ret")))
    ret(registers, memory);

  if(!(strcmp(decoder->opcode, "subl")))
    subl(decoder->operand1, decoder->operand2, registers);

return 0;
} // Done executing


int main(int argc, char* argv[])
{
  Decoder decoder;
  Registers registers;
  Reader reader;
  Instruction ins;
  int memory[1001];  

  initialize(&registers, memory); //initialize registers and memory
  read(argv[1], &reader); // Send file to reader.c

  while(registers.regs[eip])  
  {
    fetch(&reader, &ins, &registers);
    d(&ins, &decoder, &registers, memory);
    execute(&decoder, &registers, memory);  
   
    // Print out the output!
    printf("%-21seip: %4d eax:%3d ebp:%4d esp: %d\n", 
          reader.lines[i].info, registers.regs[eip],
          registers.regs[eax], registers.regs[ebp],
          registers.regs[esp]); 
  } //Fetch, decode, execute loop. Exits when eip = 0. (when ret is hit)

   
return 0;
} // main() 
    

