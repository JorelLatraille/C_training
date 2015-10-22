#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MOVE_LEN 4
#define MOVE_LEN 3
#define NUM_ROWS 3
#define NUM_COLS NUM_ROWS
#define PLAYER_ONE "X"
#define PLAYER_TWO "O"
#define PLAYER_ONE_VAL 3
#define PLAYER_TWO_VAL 4
#define PLAYER_ONE_WIN PLAYER_ONE_VAL * NUM_ROWS
#define PLAYER_TWO_WIN PLAYER_TWO_VAL * NUM_ROWS
#define DRAW 1

int** createBoard() {
    // allocate Rows rows, each row is a pointer to int
    int **board = (int **)malloc(NUM_ROWS * sizeof(int *));

    // for each row allocate Cols ints
    for (int row = 0; row < NUM_ROWS; row++) {
        board[row] = (int *)malloc(NUM_COLS * sizeof(int));
    }

    return board;
}

// you must supply the number of rows
void freeBoard(int **board) {
    // first free each row
    for (int row = 0; row < NUM_ROWS; row++) {
         free(board[row]);
    }

    // Eventually free the memory of the pointers to the rows
    free(board);
 }

char* concatString(char *s1, char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1); // +1 for the zero-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void printBoard(int **board) {
    int intSize = sizeof(int);
    int numRows = (sizeof(board) / intSize) + 1;
    char *underscors = "----";
    char *conUnderscors = "";
    for(int i=0; i<numRows; i++){
        conUnderscors = concatString(conUnderscors,underscors);
    }
    // we need to add one last underscore
    char *underscor = "-";
    conUnderscors = concatString(conUnderscors, underscor);
    printf("%s\n", conUnderscors);
    for(int row=0; row<numRows; row++) {
        printf("|");
        int numCols = (sizeof(board[row]) / intSize) + 1;
        for (int col=0; col<=numCols; col++) {
            if (col == numCols) {
                printf("\n%s\n", conUnderscors);
            }
            else {
                switch(board[row][col]){
                    case 0:
                        printf("   |");
                        continue;
                    case PLAYER_ONE_VAL:
                        printf(" %s |", PLAYER_ONE);
                        continue;
                    case PLAYER_TWO_VAL:
                        printf(" %s |", PLAYER_TWO);
                        continue;
                    default:
                        printf("   |");
                }
            }
        }
    }
}

int evalMove(int **board, char *player, int *move){
    int playerVal = 0;
    if(player == PLAYER_ONE){
        playerVal = PLAYER_ONE_VAL;
    }
    if(player == PLAYER_TWO){
        playerVal = PLAYER_TWO_VAL;
    }
    // check if it is a valid move
    if(board[move[0]][move[1]] != 0){
        return 0;
    }
    board[move[0]][move[1]] = playerVal;
    printBoard(board);
    return 1;
}

void getPlayerMove(int **board, char *player, int *finalMove){
    bool valid = false;
    while(valid != true){
        char move[MAX_MOVE_LEN] = "   ";
        printf("Player %s please enter your move e.g. 0,1: ", player);
        fgets(move, MAX_MOVE_LEN+1, stdin);
        char *posChars;
        finalMove[0] = (int)strtol(move, &posChars, 10);
        if (finalMove[0] >= NUM_ROWS){
            printf("The position does not exist please try again.\n");
            continue;
        }
        finalMove[1] = (int)strtol(&posChars[1], &posChars, 10);
        if (finalMove[1] >= NUM_COLS){
            printf("The position does not exist please try again.\n");
            continue;
        }
        if (evalMove(board, player, finalMove) == 0){
            printf("The position is already taken please try again.\n");
            continue;
        }
        printf("%d,%d\n", finalMove[0], finalMove[1]);
        valid = true;
    }
}

int checkWin(int val){
    switch(val){
        case PLAYER_ONE_WIN:
            return PLAYER_ONE_VAL;
        case PLAYER_TWO_WIN:
            return PLAYER_TWO_VAL;
    }
    return 0;
}

int evalBoard(int **board){
    int sumRow;
    int sumCol;
    int sumHoriz1 = 0;
    int usedPositions = 0;
    int result;
    for(int row=0; row<NUM_ROWS; row++) {
        sumRow = 0;
        sumCol = 0;
        for (int col=0; col<NUM_COLS; col++) {
            sumRow += (int)board[row][col];
            sumCol += (int)board[col][row];
            if (row == col){
                sumHoriz1 += (int)board[row][col];
            }
            if (board[row][col] != 0){
                usedPositions += 1;
            }

        result = checkWin(sumRow);
        if (result){
            return result;
        }
        result = checkWin(sumCol);
        if (result){
            return result;
        }
        }
    result = checkWin(sumHoriz1);
    if (result){
        return result;
    }
    }
    int sumHoriz2 = (int)board[0][NUM_COLS-1] + (int)board[NUM_ROWS/2][NUM_COLS/2] + (int)board[NUM_ROWS-1][0];
    switch(sumHoriz2){
        case PLAYER_ONE_WIN:
            return PLAYER_ONE_VAL;
        case PLAYER_TWO_WIN:
            return PLAYER_TWO_VAL;
    }
    if (usedPositions == (NUM_ROWS * NUM_COLS)){
        return DRAW;
    }
    return 0;
}

int main() {
    int matchResult = 0;
    int **board = createBoard();
    printBoard(board);
    char *currentPlayer = PLAYER_ONE;
    while(matchResult == 0){
        int move[2];
        getPlayerMove(board, currentPlayer, move);
        matchResult = evalBoard(board);
        if (currentPlayer == PLAYER_ONE){
            currentPlayer = PLAYER_TWO;
        }
        else {
            currentPlayer = PLAYER_ONE;
        }
    }
    if (matchResult == PLAYER_ONE_VAL){
        printf("Player %s WON!\n", PLAYER_ONE);
    }
    if (matchResult == PLAYER_TWO_VAL){
        printf("Player %s WON!\n", PLAYER_TWO);
    }
    if (matchResult == DRAW){
        printf("DRAW!\n");
    }
    // clean up the memory
    freeBoard(board);

    return 0;
}