#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/palindrom.h"


bool isPalindrome(int x) {
    int n = x;
    int rev = 0;
    while (x > 0) {
        int dig = x % 10;
        rev = rev * 10 + dig;
        x = x / 10;
    }

    return n == rev;
}

int reverse(int x){
    long res = 0;
    while ( x != 0) {
        int b = x % 10;
        x = (x-b) / 10;
        res = res * 10 + b;
    }

    if (res > INT_MAX || INT_MIN > res) {
        res = 0;
    }
    return res;
}
