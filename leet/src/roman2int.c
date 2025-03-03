#include "../include/roman2int.h"

int romanToInt(char *s) {
    int max_roman = 7;
    int result = 0;
    char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int values[] = {1,5,10,50,100,500,1000};
    
    char pre_idx = 0;
    while (*s != '\0') {
        int i = 0;
        while (i < max_roman && *s != symbols[i]) i++;

        if (i < max_roman) {
            if (i > pre_idx) {
                result = result -(2*values[pre_idx]);
            }
            result += values[i];
            pre_idx = i;
        }

        ++s;
    }

    return result;
}
