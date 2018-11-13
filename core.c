#include "Ship.h"
#include "Board.h"
#include <stdio.h>

void PrintBoard(Board * b) {
	for(int i = 0; i < 11; i++) {
		for(int j = 0; j < 11; j++) {
			printf("%d", b->board[i][j]);
		}
		printf("/n");
	}
}

int core_main(int argc, const char * argv[]) {
    Board * b = CreateBoard();
    PrintBoard(b);
    return 1;
}
