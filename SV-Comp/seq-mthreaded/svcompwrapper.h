// Wrapper code starts
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
int seed = 0;
const char *file_name = "file.txt";

int __VERIFIER_nondet_int(){ 
  FILE *fp = fopen(file_name, "r");
  char data[100][1000];
  int line = 0;
  while (fscanf(fp, "%s", data[line++]) != EOF);
  int value = atoi(data[seed++]);
  FILE * input_file = fopen("input_xml", "a");
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);
  fclose(input_file);
  return value;
}

_Bool __VERIFIER_nondet_bool(){ 
  //FILE *fp = fopen(file_name, "r");
  char file_content[100];
  char input[100];
  bool value;
  while (fgets(file_content, sizeof(file_content), stdin));
  int j;
  j=0;
  for (int i =0; i<strlen(file_content); i++){
    if(file_content[i] != ' ')
        input[j++] = file_content[i];}
  FILE * input_file = fopen("input_xml", "a");
  value = input[seed++];
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);
  fclose(input_file);
  return value;
}

char __VERIFIER_nondet_char(){ 
  //FILE *fp = fopen(file_name, "r");
  char file_content[100];
  char input[100];
  char value;
  while (fgets(file_content, sizeof(file_content), stdin));
  int j;
  j=0;
  for (int i =0; i<strlen(file_content); i++){
    if(file_content[i] != ' ')
        input[j++] = file_content[i];}
  FILE * input_file = fopen("input_xml", "a");
  value = input[seed++];
  fprintf(input_file, "<input type=\"input\">%c</input>\n", value);
  fclose(input_file);
  return value;
}

char __VERIFIER_nondet_uchar(){ 
  //FILE *fp = fopen(file_name, "r");
  char file_content[100];
  char input[100];
  char value;
  while (fgets(file_content, sizeof(file_content), stdin));
  int j;
  j=0;
  for (int i =0; i<strlen(file_content); i++){
    if(file_content[i] != ' ')
        input[j++] = file_content[i];}
  FILE * input_file = fopen("input_xml", "a");
  value = input[seed++];
  fprintf(input_file, "<input type=\"input\">%c</input>\n", value);
  fclose(input_file);
  return value;
}

void __VERIFIER_error(){
   abort();
}

void __VERIFIER_assume(int expression) { if (!expression) { LOOP: goto LOOP; }; return; }

// End wrapper code