#include <stdio.h>
#include <stdlib.h>
// Some global macros throughout this program
#define MAX_USERS    100
#define MAX_STRLEN   64

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(void) {
    const char *file_name = "file.txt";
    FILE *fp = fopen(file_name, "r");
    char name_list[MAX_USERS][MAX_STRLEN];
    int count = 0;
    int seed = 0;
    // Using perror() is the best option here
    if (fp == NULL) {
        perror(file_name);
        return EXIT_FAILURE;
    }

    // Reading the file contents and saving that into 2-D array
    while (fscanf(fp, "%s", name_list[count++]) != EOF)
        ;
    int value = atoi(name_list[seed++]);
    // Displaying the saved array contents        
    for (int i = 0; i < count - 1; i++)
        fprintf(stdout, "%s\n", name_list[i]);

    return 0;
}