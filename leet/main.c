#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096


int main() {
    printf("Start loading file './test.csv'\n");
    FILE *csv_file = fopen("./test.csv", "r");

    if (!csv_file) {
        perror("fopen failed. This may be caused due to missing permission or an non existing file.");
        return EXIT_FAILURE;
    }

    size_t ret;
    char buffer[BUFFER_SIZE]; 
    size_t succ_read = fread(buffer, sizeof(*buffer), BUFFER_SIZE, csv_file);


    printf("Close file. Content read into buffer\n");
    fclose(csv_file);

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

    printf("Columns: %i\n", columns);
    char **header = (char**)malloc(sizeof(char*) * columns);

    if (header == NULL) return EXIT_FAILURE;
    char *valeus[columns][rows]; 

    i = 0;
    int column_cursor = 0;
    int column_start = 0;

    char *header_name;
    while(buffer[i] != '\n')
    {
        if ( ',' == buffer[i]) {

            header_name = (char*)malloc(sizeof(char)* (i- column_start));

            //strncpy((header[column_cursor]), (buffer+column_start), i - column_start);
            header[column_cursor] = header_name;
            column_cursor++;
            printf("Create memory for: %i - %i (size: %i)\n", column_start, i, (i - column_start));
            column_start = i+1;
        }
        i++;
    }
    printf("Create memory for: %i - %i (size: %i)\n", column_start, i, (i - column_start));
    header_name = (char*)malloc(sizeof(char)* (i - column_start));

    *(header+column_cursor) = header_name;
    column_cursor=0;

    
    printf("Clean up memory after use\n");
    for (int e = 0; e < columns; e++)
    {
        printf("free %i\n", e);
        free(header[e]);
    }
    free(header);
    printf("End of cleaning\n");
    
    return 0;
}
