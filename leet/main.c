#include<stdbool.h>
#include <stdio.h>
// #include "include/palindrom.h"


/*
int main() {
    bool isPal = isPalindrome(-121);
    int r = reverse(123);
    printf("Hello WOrld");
}
*/

#define BUFFER_SIZE 32


int main() {
    FILE *csv_file = fopen("./test.csv", "r");
    size_t ret;
    unsigned char buffer[BUFFER_SIZE]; 
    size_t succ_read = fread(buffer, sizeof(*buffer), BUFFER_SIZE, csv_file);

    // ID,NAME,VALUE
    char *header[3] = {"ID", "NAME", "VALUES" };
    char ***values;

    int i = 0;
    
    int count = 0;
    while(buffer[i] != '\n')
    {
        if (',' == buffer[i]) count++;

        i++;
    }

    if (count != 0) count++;

    printf("Columns: %i\n", count);
    
    printf("Hello World\n");
    fclose(csv_file);
}
