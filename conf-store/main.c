#include <stdio.h>

#define CONF_FILE_ALREADY_EXISTS 1
#define CONF_FILE_SUCCESS 0
#define CONF_FILE_ERROR -1

int conf_store_load(const char *filepath, FILE *file, void *value);
int conf_store_write(const char *filepath, FILE *file);

int main(int arg_len, char **args) {

    printf("Arguments: %i",arg_len);
    FILE file;
    conf_store_load("./test", &file, NULL);
    return 0;
}


/*Loads a configuration file if it doesn't already exist try
 * to create the file and after that load it. 
*
* version 1 laods all of the contant of the configuration file
* into the void *value  which should be just a *char. 
*/
int conf_store_load(const char *filepath, FILE *file, void *value) {
    file = fopen(filepath, "r");
    fread();
    return CONF_FILE_ERROR;
}
