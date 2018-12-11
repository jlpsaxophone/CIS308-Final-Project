//main.c
//Board implementation

#include "Board.h"
#include "Ship.h"
#include "Placement.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum turn {human, cpu} turn;

//Creates a blank board and fills it with all 0's
Board * CreateBoard() {
    Board * b = malloc(sizeof(Board));
    char c = 'A';
    for(int i = 1; i < 10; i++) {
        b->board[0][i] = c;
	c++;
    }
   
    for(int j = 0; j < 10; j++) {
        b->board[j][0] = j + '0';
    }
    for(int k = 1; k < 10; k++) {
        for(int l = 1; l < 10; l++) {
                b->board[k][l] = '0';
        }
    }
    return b;
}


//Prints board to the console
void PrintBoard(Board * b) {
        for(int i = 0; i < 11; i++) {
                for(int j = 0; j < 11; j++) {
                        printf("%c", b->board[j][i]);
                }
                printf("\n");
        }
}


//Method is called when it's the user's turn to guess
void UserTurn(Board * enemyB) {
	char * row;
	int * col;

	printf("Enter a row(A-J): ");
	scanf("%s", row);
	printf("Enter a column(1-9): ");
	scanf("%d", col);
	//call CheckBoard to see what is at the position that was guessed
	//char guess = CheckBoard(enemyB, row, col);
	//GuessResult(enemyB, guess);
	//end turn, change to CPU's turn here or in main method?
}

//Checks the place that the player guessed on the board
char CheckBoard(Board * enemyB, char row, int col) {
	char guess;
	char c = col + '0';
	if (enemyB->board[row][c] != '0') {
		guess = 'R';
		return guess;
	}
	else if (enemyB->board[row][c] == 'S') {
		enemyB->board[row][c] = 'X';
		guess = 'X';
		return guess;
	}
	else {
		enemyB->board[row][c] = '1';
		guess = '1';
		return guess;
	}
}

void GuessResult(Board * enemyB, char guess) {
	//reprint board here?
	PrintBoard(enemyB);
	if (guess = 'R') {
		printf("\n You have already guessed there! Try Again! \n");
		//call turn method again
	}
	else if (guess = '1') {
		printf("\n You missed! \n");
	}
	else if (guess = 'X') {
		printf("\n You hit a ship! \n");
	}
	else {
		printf("\n Something went wrong \n");
		//just for testing purposes
	}
}

int IsSafe(direction d, Board * b, Ship * s, int startx, int starty) {
    if(d == horizontal) {
                for(int i = 0; i < s->size; i++) {
                        if(b->board[startx + i][starty] != '0') {return 0;}
                }
        }
        else {
                for(int i = 0; i < s->size; i++) {
                        if(b->board[startx][starty+ i] != '0') {return 0;}
                }
    }
        return 1;
}

ShipPosition * FindSpot(Board * b, Ship * s) {
        ShipPosition * sp = malloc(sizeof(ShipPosition));
	srand(time(NULL));
        int determiner = rand() % 2;
	//printf("%d\n", determiner);
        if(determiner == 0) {sp->d = horizontal;}
        else if(determiner == 1) {sp->d = vertical;}

        int maxpoint = (9 - s->size);

        if((sp->d) == horizontal) {
                srand(time(NULL));
		sp->xcoordinate = rand() % (maxpoint - 1 + 1) + 1;
                srand(time(NULL));
		sp->ycoordinate = rand() % (9 - 1 + 1) + 1;
        }
        else if(sp->d == vertical) {
		srand(time(NULL));
                sp->xcoordinate = rand() % (9 - 1 + 1) + 1;
		srand(time(NULL));
                sp->ycoordinate = rand() % (maxpoint- 1 + 1) + 1;
        }
	//printf("%d\n", sp->xcoordinate);
	//printf("%d\n", sp->ycoordinate);
        return sp;
}

void PlaceShip(Board * b, Ship * s, char representer) {
        ShipPosition * sp = FindSpot(b, s);
        //checks for safety
        while((IsSafe(sp->d, b, s, sp->xcoordinate, sp->ycoordinate)) != 1) {
               ShipPosition * sp = FindSpot(b, s);
         }
        //places on board
        if(sp->d == 0) {
                for(int i = 0; i < s->size; i++) {
                        b->board[sp->xcoordinate + i][sp->ycoordinate] = representer;
                }
        }
        else {
                for(int i = 0; i < s->size; i++) {
                        b->board[sp->xcoordinate][sp->ycoordinate + i] = representer;
                }
        }
	free(sp);
}

int main(int argc, const char * argv[]) {
    Board * PlayerBoard = CreateBoard();
    Board * CPUBoard = CreateBoard();
    Board * CPUViewBoard = CreateBoard();
    Ship * DestroyerHuman = malloc(sizeof(Ship));
    DestroyerHuman->size = 2;
    Ship * DestroyerCPU = malloc(sizeof(Ship));
    DestroyerCPU->size = 2;
    Ship * SubHuman = malloc(sizeof(Ship));
    SubHuman->size = 3;
    Ship * SubCPU = malloc(sizeof(Ship));
    SubCPU->size = 3;
    Ship * CruiserHuman = malloc(sizeof(Ship));
    CruiserHuman->size = 3;
    Ship * CruiserCPU = malloc(sizeof(Ship));
    CruiserCPU->size = 3;
    Ship * BattleshipHuman = malloc(sizeof(Ship));
    BattleshipHuman->size = 4;
    Ship * BattleshipCPU = malloc(sizeof(Ship));
    BattleshipCPU->size = 4;
    Ship * CarrierHuman = malloc(sizeof(Ship));
    CarrierHuman->size = 5;
    Ship * CarrierCPU = malloc(sizeof(Ship));
    CarrierCPU->size = 5;
    //all ships sizes are 5, check size before dealing with ship segments
    int HumanShipCounter = 5;
    int CPUShipCounter = 5;
    //place ships using method
    printf("%d\n", PlayerBoard->board[0][3]);
    PlaceShip(PlayerBoard, DestroyerHuman, 'S');
    //printf("\nShip printed\n");
    PlaceShip(PlayerBoard, SubHuman, 'S');
    //PlaceShip(PlayerBoard, CruiserHuman, 'S');
    //PlaceShip(PlayerBoard, BattleshipHuman, 'S');
    /*PlaceShip(PlayerBoard, CarrierHuman, 'S');
    PlaceShip(CPUBoard, DestroyerCPU, 'S');
    PlaceShip(CPUBoard, SubCPU, 'S');
    PlaceShip(CPUBoard, CruiserCPU, 'S');
    PlaceShip(CPUBoard, BattleshipCPU, 'S');
    PlaceShip(CPUBoard, CarrierCPU, 'S');*/
    PrintBoard(PlayerBoard);




    //free everything at very end of program
    return 1;
}










