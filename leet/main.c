#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

typedef struct{
    int columns;
    int rows;
    char **header;
    char ***values;
} csv;

int csv_load(csv *csv, FILE *file);
int csv_destroy(csv *csv);

int main() {
    printf("Start loading file './test.csv'\n");
    FILE *csv_file = fopen("./test.csv", "r");

    csv content = { 0, 0, NULL, NULL };

    printf("Pre csv_load\n");
    csv_load(&content, csv_file);

    fclose(csv_file);

    printf("Close file. Content read into buffer\n");
    
    
    return 0;
}

int csv_load(csv *csv, FILE *file) {

    if (!file) {
        perror("fopen failed. This may be caused due to missing permission or an non existing file.");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE]; 
    size_t ret;

    ret = fread(buffer, sizeof(*buffer), BUFFER_SIZE, file);
    fclose(file);

    int i = 0;
    
    // prep csv object
    printf("Does this work\n");
    csv->rows = 0;
    csv->columns = 0;

    int column_cursor = 0;
    while (buffer[i] != '\0')
    {
        if ('\n' == buffer[i]) csv->rows++;
        if (',' == buffer[i]) csv->columns++;
        i++;
    }
    if (csv->columns != 0) csv->columns++;
    csv->header = (char**)malloc(sizeof(char*) * csv->columns);
    csv->values = (char***)malloc(sizeof(char**) * csv->columns);

    i = 0;
    int column_start = 0;
    int rows = -1;
    while(buffer[i] != '\0')
    {
        if (',' == buffer[i]) {
            if (rows == -1) {
                char *cell_content = strndup(&buffer[column_start], i - column_start);
                csv->header[column_cursor] = cell_content;
                column_cursor++;
                column_start = i+1;
            }
        }

        if ('\n' == buffer[i]) {
            if (rows == -1)
            {
                char *header_name = strndup(&buffer[column_start], i - column_start);
                csv->header[column_cursor] = header_name;
            }
        }
        i++;
    }


    if (csv->header == NULL) return EXIT_FAILURE;
    csv->header[column_cursor] = strndup(&buffer[column_start], i - column_start);
    column_cursor=0;
}

int csv_destroy(csv *csv) {
    printf("Clean up memory after use\n");
    for (int e = 0; e < csv->columns; e++)
    {
        printf("Print header %i: %s\n", e, csv->header[e]);
        free(csv->header[e]);
    }
    free(csv->header);
    printf("End of cleaning\n");
    return EXIT_SUCCESS;
}
