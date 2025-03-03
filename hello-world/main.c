#include "hello_world.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
    int sizeA = strlen(a) - 1;
    int sizeB = strlen(b) - 1;

    char cmpA = '0';
    char cmpB = '0';
    char head = '0';

    int resIndex = (sizeA < sizeB ? sizeB : sizeA) + 2;

    char *buffer = (char *)malloc(resIndex);
    for (int i = 0; i < resIndex; i++) {
        buffer[i] = '0';
    }

    buffer[resIndex--] = '\0';

    while (sizeA >= 0 || sizeB >= 0 || (resIndex >= 0 && head == '1')) {
        cmpA = sizeA < 0 ? '0' : a[sizeA];
        cmpB = sizeB < 0 ? '0' : b[sizeB];

        if ((cmpA == '1' && cmpB == '1') ||
            ((cmpA == '1' || cmpB == '1') && head == '1')) {
            if (head == '1' && cmpA == '1' && cmpB == '1') {
                buffer[resIndex] = '1';
            } else {
                buffer[resIndex] = '0';
            }
            head = '1';
        } else if ((cmpA == '0' || cmpB == '0' || head == '0') &&
            (cmpA == '1' || cmpB == '1' || head == '1')) {
            head = '0';
            buffer[resIndex] = '1';
        } else {
            buffer[resIndex] = '0';
            head = '0';
        }

        resIndex--;
        sizeA--;
        sizeB--;
    }

    char *res = (char *)strdup(buffer + (buffer[0] == '0' ? 1 : 0));
    if (!res)
        return NULL;
    free(buffer);

    return res;
}

char *addBinaryWorking(char *a, char *b) {
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char *output = (char *)malloc(sizeOutput + 1);
    int sum = 0;

    output[sizeOutput] = '\0';

    while (sizeA > 0 || sizeB > 0 || sum > 0) {

        if (sizeA > 0) {
            sum += a[--sizeA] - '0';
        }
        if (sizeB > 0) {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    return output + sizeOutput;
}

int main() {
    char *b = addBinary("10", "1011");
    char *c = addBinary("1111", "1");
    free(b);
    free(c);
    b = NULL;
    return 0;
}
