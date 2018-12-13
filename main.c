#include "Board.h"
#include "Ship.h"
#include "Placement.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum turn {human, cpu, gameOver} turn;

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

//Checks the place that the player guessed on the board
void CheckBoard(Board * enemyB, Board * enemyvb, char row, int col) {
	char guess;
	int r = row - 64;
	if ((enemyvb->board[col][r]) != '0') {
		printf("\nYou have already guessed there!\n");
	}
	else if (enemyB->board[col][r] == 'S') {
		enemyB->board[col][r] = 'X';
		enemyvb->board[col][r] = 'X';
		printf("\nYou hit a ship!\n");
	}
	else if(enemyB->board[col][r] == '0'){
		enemyB->board[col][r] = '1';
		enemyvb->board[col][r] = '1';
		printf("\nYou missed!\n");
	}
}

//Method is called when it's the user's turn to guess
void UserTurn(Board * enemyB, Board * enemyvb) {
        char * row;
        int col;
	printf("\nEnemy's Board (for demo):\n");
	PrintBoard(enemyB);
        printf("Enter a row(A-I): ");
        scanf("%s", row);
        printf("Enter a column(1-9): ");
        scanf("%d", &col);
        //call CheckBoard to see what is at the position that was guessed
        CheckBoard(enemyB, enemyvb, *row, col);
	printf("\n------------------------------------\n");
}

//Checks the place that the computer guessed on the board
void CPUTurn(Board * userB) {
	int row = rand() % (9) + 1;
        int col = rand() % (9) + 1;
        if (userB->board[col][row] == 'S') {
                userB->board[col][row] = 'X';
                printf("\nThe computer hit your ship!\n");
        }
        else if(userB->board[col][row] == '0'){
                userB->board[col][row] = '1';
                printf("\nThe computer missed!\n");
        }
	else if ((userB->board[col][row]) != '0') {
                CPUTurn(userB);
        }
}

//Sees if the ship can be placed on the board at the spot that was found
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

//Finds a spot for the ship to be placed
ShipPosition * FindSpot(Board * b, Ship * s) {
        ShipPosition * sp = malloc(sizeof(ShipPosition));

	int determiner = rand() % 2;
        if(determiner == 0) {sp->d = horizontal;}
        else {sp->d = vertical;}

        int maxpoint = (9 - s->size);

        if((sp->d) == horizontal) {
		sp->xcoordinate = rand() % (maxpoint - 1 + 1) + 1;
		sp->ycoordinate = rand() % (9 - 1 + 1) + 1;
        }
        else if(sp->d == vertical) {
                sp->xcoordinate = rand() % (9 - 1 + 1) + 1;
                sp->ycoordinate = rand() % (maxpoint- 1 + 1) + 1;
        }
        return sp;
}

void PlaceShip(Board * b, Ship * s, char representer) {
        ShipPosition * sp = FindSpot(b, s);
        //checks for safety
        while((IsSafe(sp->d, b, s, sp->xcoordinate, sp->ycoordinate)) != 1) {
		free(sp);
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

int CheckWin(Board * b) {
	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) {
			if (b->board[j][i] == 'S') {
				return 0;
			}
		}
	}
	return 1;
}

//The main method
int main(int argc, const char * argv[]) {
	//used for randomly generating numbers
	srand(time(NULL));

	//initializes boards
	Board * PlayerBoard = CreateBoard();
    	Board * CPUBoard = CreateBoard();
    	Board * CPUViewBoard = CreateBoard();

	//initializes ships
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

	//places all the ships on the boards
    	PlaceShip(PlayerBoard, DestroyerHuman, 'S');
    	PlaceShip(PlayerBoard, SubHuman, 'S');
    	PlaceShip(PlayerBoard, CruiserHuman, 'S');
    	PlaceShip(PlayerBoard, BattleshipHuman, 'S');
    	PlaceShip(PlayerBoard, CarrierHuman, 'S');
    	PlaceShip(CPUBoard, DestroyerCPU, 'S');
    	PlaceShip(CPUBoard, SubCPU, 'S');
    	PlaceShip(CPUBoard, CruiserCPU, 'S');
    	PlaceShip(CPUBoard, BattleshipCPU, 'S');
    	PlaceShip(CPUBoard, CarrierCPU, 'S');

	turn t = human;

	while(t != gameOver) {
		if(t == human) {
		//player's turn
		printf("\nYour Guesses:\n");
		PrintBoard(CPUViewBoard);
		printf("\nYour Board:\n");
		PrintBoard(PlayerBoard);
		UserTurn(CPUBoard, CPUViewBoard);
			if (CheckWin(CPUBoard) == 1) {
				printf("\nYou won!\n");
				printf("\n------------------------------------\n\n");
				t = gameOver;
			}
			else {
				t = cpu;
			}
		}
		if (t == cpu) {
			//CPU's turn
			printf("\nThe computer's turn...\n");
			CPUTurn(PlayerBoard);
			if (CheckWin(PlayerBoard) == 1) {
				printf("\nYou lost.\n");
				printf("\n------------------------------------\n\n");
				t = gameOver;
			}
			else {
				printf("\n------------------------------------\n");
				t = human;
			}
		}
	}

	//free everything at very end of program
	free(PlayerBoard);
	free(CPUBoard);
	free(CPUViewBoard);

    	return 1;
}




