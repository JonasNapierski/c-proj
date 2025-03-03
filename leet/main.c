#include<stdbool.h>
#include <stdio.h>

#include "include/test.h"

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    return false;
}


int main() {
    test_hello();
    char* board[9][9] = {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };

    for (int y = 0; y < 9; y++) {
        if (y % 3 == 0) {
            printf("+---+---+---+\n");
        }
        for(int i = 0; i<9; i++) {
            if (i % 3 == 0) {
                printf("|%s", board[y][i]);
            }else {
                printf("%s",board[y][i]);
            }
        }
        printf("|\n");
    }
    printf("+---+---+---+\n");
    

}
