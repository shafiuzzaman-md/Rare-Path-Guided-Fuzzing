// Wrapper code starts
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//constants for maximum number of lines in the file and max length of a line
#define MAX_LINES 100
#define MAX_LEN 1000

int seed = 0;
int inputs[100];

void get_inputs(char file_name[256])
{
  char data[MAX_LINES][MAX_LEN];
  int line = 0;

  FILE *file;
  file = fopen(file_name, "r");
 
  while (!feof(file) && !ferror(file)){
    if (fgets(data[line], MAX_LEN, file) != NULL)
      line++;
  }
   
  fclose(file);
  
  char c_input;
  for (int i = 0; i < line; i++){
      c_input = data[i][0];
      inputs[i] = atoi(&c_input);
  }  
}

char __VERIFIER_nondet_char(){ 
  char value;
  value =  inputs[seed++];
  return value;
}

unsigned char __VERIFIER_nondet_uchar(void){ 
  char value;
  value = inputs[seed++];
  return value;
}

int __VERIFIER_nondet_int(){ 
  int value;
  value = inputs[seed++];
  return value;
}

int __VERIFIER_nondet_uint(){ 
  int value;
  value = inputs[seed++];
  return value;
}


bool __VERIFIER_nondet_bool(){ 
  int value;
  value = inputs[seed++];
  return value;
}


void __VERIFIER_error(){
   abort();
}

void __VERIFIER_assume(int expression) { if (!expression) { LOOP: goto LOOP; }; return; }

// End wrapper code