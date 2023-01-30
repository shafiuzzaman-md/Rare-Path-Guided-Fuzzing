
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    char ptr[20];
    int tmp = 0;
    FILE *fp = fopen(argv[1], "r");
    fgets(ptr, sizeof(ptr), fp);
   if((int)(ptr[0] == 65)){
     tmp = 1;
     printf("%d",ptr[0]);
   }
   if((int)(ptr[1] == 66)){
     tmp = 2;
     printf("%d",ptr[0]);
   }
   if((int)(ptr[2] == 67)){
     tmp = 3;
     printf("%d",ptr[0]);
   }
    if (!tmp)
    {
        abort();
    }
    return 0;
}
