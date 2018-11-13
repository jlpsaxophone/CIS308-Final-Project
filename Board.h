//Board struct

typedef struct Board {
    char board[11][11];
} Board;

Board * CreateBoard() {
    Board * b = new * Board;
    for(int i = 0; i < 11; i++) {
        b->board[0][i] = (char)i;
    }
    char c = 'A';
    for(int j = 1; j < 10; c++) {
        b->board[j][0] = c;
        c++;
    }
    for(int k = 1; k < 10; k++) {
        for(int l = 1; l < 10; l++) {
                b->board[k][l] = '0';
        }
    }
    return Board;
}




