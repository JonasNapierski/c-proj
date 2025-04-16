#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096


int main() {
    printf("Hello World\n");
    FILE *csv_file = fopen("./test.csv", "r");
    size_t ret;
    char buffer[BUFFER_SIZE]; 
    size_t succ_read = fread(buffer, sizeof(*buffer), BUFFER_SIZE, csv_file);

    // ID,NAME,VALUE
    int i = 0;
    
    int columns = 0;
    int rows = 0;
    while(buffer[i] != '\n')
    {
        if (',' == buffer[i]) columns++;

        i++;
    }

    if (columns != 0) columns++;
    if (rows < 0) rows--;

    printf("Hello World\n");
    char **header = (char**)malloc(sizeof(char*) * columns);

    if (header == NULL) return -1;
    char *valeus[columns][rows]; 

    i = 0;
    int column_cursor = 0;
    int column_start = 0;

    while(buffer[i] != '\n')
    {
        if ( ',' == buffer[i]) {
            char *header_name = (char*)malloc(sizeof(char)* (i- column_start));

            //strncpy((header[column_cursor]), (buffer+column_start), i - column_start);
            *(header+column_cursor) = header_name;
            column_cursor++;
            printf("This got triggered\n");
            column_start = i+1;
        }
        i++;
    }
    char *header_name = (char*)malloc(sizeof(char)* (i- column_start));

    *(header+column_cursor) = header_name;
    column_cursor++;
    printf("This got triggered\n");
    column_start = i+1;

    printf("Columns: %i\n", columns);
    
    printf("Clean up memory after use\n");
    for (int e = 0; e < columns; e++)
    {
        printf("free %i\n", e);
        free((header+e));
    }
    free(header);
    printf("End of cleaning\n");
    
    fclose(csv_file);
    return 0;
}
