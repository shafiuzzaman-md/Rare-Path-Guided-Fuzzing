// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
	FILE* ptr;
	char str[50];
    char data[50];
	ptr = fopen("file.txt", "r");

	if (NULL == ptr) {
		printf("file can't be opened \n");
	}

	printf("content of this file are \n");
   int j;
	while (fgets(str, 50, ptr)) {
		printf("%s", str);
	}
    j=0;
    for (int i =0; i<strlen(str); i++){
    if(str[i] != ' ')
        data[j++] = str[i];
    }
	fclose(ptr);
	return 0;
}
