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


int main() {
    FILE *csv_file = fopen("./test.csv", "r");
    size_t ret;
    unsigned char buffer[csv_file]; 
    fread(void *, unsigned long, unsigned long, csv_file);
    printf("Hello World");
}
