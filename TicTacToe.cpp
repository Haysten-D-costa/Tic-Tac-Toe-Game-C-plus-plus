#include <iostream>
#include <conio.h>
#include <ctime>

#define GRID_SIZE 3

bool yourTurn = true;
int current_row = 0, current_col = 0;
char grid[GRID_SIZE][GRID_SIZE] = { // grid-board....
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void displayGrid();  // function displays grid....
void playerMove();   // function for player move....
void computerMove(); // function for computer move....
void move(char key); // function to move on the grid (player move)....
void place(int x, int y, bool turn); // function to place a character in the grid....
bool checkWinner(char grid[GRID_SIZE][GRID_SIZE]); // function to check for wins....
bool checkTie(char grid[GRID_SIZE][GRID_SIZE]);    // function to check for draw....

int main() { // MAIN FUNCTION-----------------------------------------------------------------------------
    while (true) {
        displayGrid();
        playerMove();
        displayGrid();
        if(checkWinner(grid)) { break; }
        else if(checkTie(grid)) {
            break;
        }
        computerMove();
        displayGrid();
        if(checkWinner(grid)) { break; }
        else if(checkTie(grid)) {
            break;
        }
        displayGrid();
    }
    return 0;
}

void displayGrid() {
    system("cls");
    std::cout << std::endl;
    std::cout << "     |     |     " << std::endl;  
    std::cout << "  " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << "  " << std::endl;  
    std::cout << "-----|-----|-----" << std::endl;  
    std::cout << "  " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << "  " << std::endl;
    std::cout << "-----|-----|-----" << std::endl;    
    std::cout << "  " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << "  " << std::endl;  
    std::cout << "     |     |     " << std::endl;  
    std::cout << std::endl;
}
void place(int x, int y, bool turn) {
    if(turn) { grid[x][y] = 'X'; } 
    else { grid[x][y] = 'O'; }
}
void move(char arrowKey) {
    if (arrowKey == 72 && current_row > 0) {
        current_row--;
    } else if (arrowKey == 80 && current_row < GRID_SIZE - 1) {
        current_row++;
    } else if (arrowKey == 75 && current_col > 0) {
        current_col--;
    } else if (arrowKey == 77 && current_col < GRID_SIZE - 1) {
        current_col++;
    }
    grid[current_row][current_col];
}
// function here, to check for winner....
void playerMove() {
    while(true) {
        int key = _getch();
        if((key == 72) || (key == 80) || (key == 75) || (key == 77)) { move(key); }
        else if((key == 13)) { 
            place(current_row, current_col, yourTurn); 
            break; // if player selects a spot, end the while loop....
        }
    }
    yourTurn = false; // invert player turn to "computer"....
}
void computerMove() {
    int row;
    int col;
    srand(time(0));
    while(true) {
        row = rand() % 9;
        col = rand() % 9;
        if(grid[row][col] == ' ') {
            place(row, col, yourTurn);
            break; // if player plays his move, end the while loop....
        }
    }
    place(row, col, yourTurn);
    yourTurn = true; // invert player turn to "player"....
}
bool checkWinner(char grid[GRID_SIZE][GRID_SIZE]) {
    if ((grid[0][0] != ' ') && (grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2])) {
        (grid[0][0] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[1][0] != ' ') && (grid[1][0] == grid[1][1]) && (grid[1][1] == grid[1][2])) {
        (grid[1][0] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[2][0] != ' ') && (grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2])) {
        (grid[2][0] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[0][0] != ' ') && (grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0])) {
        (grid[0][0] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[0][1] != ' ') && (grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1])) {
        (grid[0][1] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[0][2] != ' ') && (grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2])) {
        (grid[0][2] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[0][0] != ' ') && (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2])) {
        (grid[0][0] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else if ((grid[0][2] != ' ') && (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0])) {
        (grid[0][2] == 'X')? std::cout << "YOU WIN !\n" : std::cout << "YOU LOSE !\n";
    } else {
        return false;
    }
    return true;
}
bool checkTie(char grid[GRID_SIZE][GRID_SIZE]) {
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(grid[i][j] == ' ') {
                return false; // more spaces remaining....
            }
        }
    }
    std::cout << "It's a TIE !\n";
    return true;
}