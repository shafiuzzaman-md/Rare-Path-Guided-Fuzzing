#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
int seed;
seed=0;
#define verifier_nondet_name(typename, type, printchar) \
type __VERIFIER_nondet_##typename(){ \
  char data[100][1000];\
  int line = 0;\
  while (fscanf(stdin, "%s", data[line++]) != EOF);\
  int value = atoi(data[seed++]);\
  FILE * input_file = fopen("input_xml", "a");\
  fprintf(input_file, "<input type=\"input\">%d</input>\n", value);\
  fclose(input_file);\
  return value;\
}

#define verifier_nondet(type, printchar) verifier_nondet_name(type, type, printchar)

void __VERIFIER_error(){
   abort();
}



verifier_nondet(int, i);

#ifdef loff_t
verifier_nondet(loff_t, lli);
#endif
#ifdef u32
verifier_nondet(u32, lli);
#endif
#ifdef sector_t
verifier_nondet(sector_t, lli);
#endif



extern void __VERIFIER_error() __attribute__ ((__noreturn__));

void __VERIFIER_assert(int cond) {
  if (!(cond)) {
    ERROR: __VERIFIER_error();
  }
  return;
}
int __VERIFIER_nondet_int();

int main()
{
  unsigned int SIZE=1;
  unsigned int j,k;
  int array[SIZE], menor;
  FILE * input_file = fopen("input_value.txt", "a");
  

  menor = __VERIFIER_nondet_int();
   fprintf(input_file, "<input type=\"menor\">%d</input>\n", menor);

  for(j=0;j<SIZE;j++) {
       array[j] = __VERIFIER_nondet_int();

       if(array[j]<=menor)
          menor = array[j];
    }

  k = __VERIFIER_nondet_int();
    fprintf(input_file, "<input type=\"k\">%d</input>\n", k);
  if (k > 0) {
     menor = menor - k;
     k = __VERIFIER_nondet_int();
     fprintf(input_file, "<input type=\"k\">%d</input>\n", k);
     if (k > 0) {
        __VERIFIER_assert(menor < k);
     }

  }
   __VERIFIER_assert(array[0]>=menor);
    fclose(input_file);
    return 0;
}