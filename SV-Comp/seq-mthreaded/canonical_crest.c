
#include <crest.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int tmp = 0;
    char id1  ;
    char st1  ;
    char nl1  ;

    CREST_char(id1);
    CREST_char(id1);
    CREST_char(id1);
   
   if((int)(id1 == 65)){
     tmp = 1;
   }
   if((int)(st1 == 66)){
     tmp = 2;
   }
   if((int)(nl1 == 67)){
     tmp = 3;
   }
    if (!tmp)
    {
        abort();
    }
    return 0;
}
