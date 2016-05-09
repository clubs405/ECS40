// Program 1 for ECS40 W16 Sean Davis
//
// Written by: Bryan Ngo and Mat Magno
//
// Program: reader.c
//
// Purpose: read into an input file and recognize instructions and operands of a .s file. 
//     - In other words, we want the important lines for the purposes of p1.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "reader.h"
#include "instruction.h"
#include "registers.h"
#include "main.h"
// Reads in a file and saves the important lines
int read(char* file, Reader *reader)
{  
  FILE *fp;
  fp = fopen(file, "r");
  char buff[80], *str, *mstr;  
  int addy = 100, i = 0, k = 0;
    // Reads file line by line until EOF
  while(fgets(buff, 80, fp) != NULL)
  {
    // If the first or second character of a line is a period, look at the next line
    if((buff[0] == '.' || buff[1] == '.'))
      continue;
    // If the line contains main, look at the next line
    if((mstr = strstr(buff, "main")))
      continue;
    // Changes all tab spaces in line to a whitespace  
    while((str = strchr(buff, '\t')) != NULL)
      *str = ' ';
    // Changes all new lines to a whitespace
    while((str = strchr(buff, '\n')) != NULL)
      *str = ' ';
    int mat = sizeof(buff);
 
    for(k = 0; k < mat; k++)
        buff[k] = buff[k + 1];
    // Allocates space for this new line and places it in reader (struct)    
    reader->lines[i].info = (char *)malloc(strlen(buff));
    strcpy(reader->lines[i].info, buff);
    // Give the struct its respective address (int)
    reader->lines[i].address = (addy + (4 * i));
    i++;
 
 } // Reads file line by line 
  
return 0;
} //Reads file line by line and saves the important stuff
