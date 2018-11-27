//main.c



//Board implementation

#include "Board.h"
#include "Ship.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum turn {human, cpu} turn;




Board * CreateBoard() {
    Board * b = malloc(sizeof(Board));
    //int test;
    //char c = ;
    for(int i = 0; i < 10; i++) {
        b->board[0][i] = i+'0';
    }
    char c2 = 'A';
    for(int j = 1; j < 10; j++) {
        b->board[j][0] = c2;
        c2++;
    }
    for(int k = 1; k < 10; k++) {
        for(int l = 1; l < 10; l++) {
                b->board[k][l] = '0';
        }
    }
    return b;
}


//core.c

void PrintBoard(Board * b) {
        for(int i = 0; i < 11; i++) {
                for(int j = 0; j < 11; j++) {
                        printf("%c", b->board[i][j]);
                }
                printf("\n");
        }
}

int main(int argc, const char * argv[]) {
    Board * PlayerBoard = CreateBoard();
    Board * CPUBoard = CreateBoard();
    Board * CPUViewBoard = CreateBoard();
    Ship * DestroyerHuman = malloc(sizeof(Ship));
    DestroyerHuman->size = 2;
    Ship * DestroyerCPU = malloc(sizeof(Ship));
    DestroyerHuman->size = 2;
    Ship * SubHuman = malloc(sizeof(Ship));
    SubHuman->size = 3;
    Ship * SubCPU = malloc(sizeof(Ship));
    SubCPU->size = 3;
    Ship * CruiserHuman = malloc(sizeof(Ship));
    SubHuman->size = 3;
    Ship * CruiserCPU = malloc(sizeof(Ship));
    SubCPU->size = 3;
    Ship * BattleshipHuman = malloc(sizeof(Ship));
    SubHuman->size = 4;
    Ship * BattleshipCPU = malloc(sizeof(Ship));
    SubCPU->size = 4;
    Ship * CarrierHuman = malloc(sizeof(Ship));
    SubHuman->size = 5;
    Ship * CarrierCPU = malloc(sizeof(Ship));
    SubCPU->size = 5;
    //all ships sizes are 5, check size before dealing with ship segments 
    int HumanShipCounter = 5;
    int CPUShipCounter = 5;
    //place ships using method
    




    //free everything at very end of program    
    return 1;
    
}









