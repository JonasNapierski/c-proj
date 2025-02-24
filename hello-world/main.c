#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hello_world.h"

char* addBinary(char* a, char* b) {
    int aIndex = strlen(a)-1;
    int bIndex = strlen(b)-1;

    char cmpA = '0';
    char cmpB = '0';
    char head = '0';

    int resIndex = aIndex;

    if (resIndex < bIndex) {
        resIndex = bIndex;
    }

    resIndex = resIndex+1;


    char *buffer = malloc((resIndex+1)*sizeof(char));
    
    for (int i = 0; i < resIndex; i++){
        buffer[i] = ' ';
    }

    buffer[resIndex+1] = '\0';
    
    while (aIndex >= 0 || bIndex >= 0 || (resIndex >= 0 && head == '1')) {

        if (aIndex < 0) {
           cmpA = '0'; 
        }else {
           cmpA = a[aIndex];
        }

        if (bIndex < 0) {
            cmpB = '0';
        }else{
            cmpB = b[bIndex];
        }

        printf("A: %i(%c), B: %i(%c) S: %s\n",aIndex, cmpA,bIndex, cmpB,buffer);

        if (cmpA == '1' && cmpB == '1') {
            if (head == '1'){
                buffer[resIndex] = '1';
            }else{
                buffer[resIndex] = '0';
            }
            head = '1';
        }else if ((cmpA == '0' || cmpB == '0' || head == '0') && (cmpA == '1' || cmpB == '1' || head == '1')) {
            head = '0';
            buffer[resIndex] = '1';
        }else {
            buffer[resIndex] = '0';
            head = '0';
        }

        --resIndex;
        --aIndex;
        --bIndex;
    }


    int j = 0;

    while (buffer[j] == ' ') j++;

    char *res = malloc((strlen(buffer) - j)* sizeof(char));

    strcpy(res,buffer+j+1);

    free(buffer);
    buffer = NULL;

    return res;

}

int main(){
    
    char* b = addBinary("1000", "1");
    printf("(%s)\n", b); 

    return 0;
}
