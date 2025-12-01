#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main()
{
    FILE *file = fopen("input", "r");

    char line[] = "L12";

    char currentLine[] = "";
    int isLeft;

    
    char buf[256];

    int count = 0;
    int position = 50;
    while(fgets(buf, sizeof(buf), file)) {
        if (buf[0] == 'L') {
            isLeft = -1;
        }else{
            isLeft = 1;
        }

        char num[256];
        memcpy(num, buf+1, sizeof(buf)-1);

        int number =  atoi(num);

        for (int i = 0; i < number; i++){
            position += isLeft;

            if (position < 0) {
                position = 99;
            }

            if (position > 99) {
                position = 0;
            }
        }

        printf("Line: %s   %i   Position: %i\n", buf, number,position);
        if (position == 0) {
            count++;
        }

    }
        
    fclose(file);

    printf("Zero was %i times includes\n", count);


    return 0;
}
