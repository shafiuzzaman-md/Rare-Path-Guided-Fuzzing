#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
int seed = 0;


void __VERIFIER_error(){
   abort();
}

extern void __VERIFIER_error() __attribute__ ((__noreturn__));

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: __VERIFIER_error();
  }
  return;
}
//int __VERIFIER_nondet_int();
int __VERIFIER_nondet_int(){ \
  char data[100][1000];\
  int line = 0;\
  while (fscanf(stdin, "%s", data[line++]) != EOF);\
  int value = atoi(data[seed++]);\
  FILE * input_file = fopen("input_xml", "a");\
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);\
  fclose(input_file);\
  return value;\
}

int __VERIFIER_nondet_bool(){ \
  char data[100][1000];\
  int line = 0;\
  while (fscanf(stdin, "%s", data[line++]) != EOF);\
  int value = atoi(data[seed++]);\
  FILE * input_file = fopen("input_xml", "a");\
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);\
  fclose(input_file);\
  return value;\
}

int __VERIFIER_nondet_char(){ \
  char data[100][1000];\
  int line = 0;\
  while (fscanf(stdin, "%s", data[line++]) != EOF);\
  char value = data[seed++][0];\
  FILE * input_file = fopen("input_xml", "a");\
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);\
  fclose(input_file);\
  return value;\
}

int __VERIFIER_nondet_uchar(){ \
  char data[100][1000];\
  int line = 0;\
  while (fscanf(stdin, "%s", data[line++]) != EOF);\
  char value = data[seed++][0];\
  FILE * input_file = fopen("input_xml", "a");\
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);\
  fclose(input_file);\
  return value;\
}