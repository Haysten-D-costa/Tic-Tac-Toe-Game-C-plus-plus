#include <iostream>
#include <conio.h>
#include <ctime> 
#include <windows.h>
#include "textstyling.h"

#define GRID_SIZE 3

bool yourTurn = true;
int current_row = 0, current_col = 0;
char grid[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

/* 
    These are function declarations for various functions used in the Tic-Tac-Toe game. Here is a brief
    explanation of each function: 
*/
void playerMove();   // function for player move....
void computerMove(); // function for computer move....
void move(char key); // function to move on the grid (player move)....
void place(int x, int y, bool turn); // function to place a character in the grid....
bool checkTie(char grid[GRID_SIZE][GRID_SIZE]);     // function to check for draw....
bool checkWinner(char grid[GRID_SIZE][GRID_SIZE]);  // function to check for wins....
void displayGrid(int current_row, int current_col); // function displays grid....

/**
 * This is the main function for a tic-tac-toe game that alternates between player and computer moves
 * until there is a winner or a tie.
 * 
 * @return The main function is returning an integer value of 0.
 */
int main() { // MAIN FUNCTION-----------------------------------------------------------------------------
    while (true) {
        displayGrid(current_row, current_col);
        playerMove();
        if(checkWinner(grid)) { break; }
        else if(checkTie(grid)) {
            break;
        }
        computerMove();
        if(checkWinner(grid)) { break; }
        else if(checkTie(grid)) {
            break;
        }
    }
    std::cout << std::endl; system("pause");
    displayGrid(-1, -1);
    return 0;
}

/**
 * The function `displayGrid` is used to display a grid with a highlighted current position.
 * 
 * @param current_row The parameter `current_row` represents the current row position in the grid. It
 * is used to highlight the current position in the grid when displaying it.
 * @param current_col The parameter `current_col` represents the current column position in the grid.
 * It is used in the `displayGrid` function to highlight the current position in the grid by changing
 * the text color and background color.
 */
void displayGrid(int current_row, int current_col) {
    system("cls");

    std::cout << "\t\t\t\t+----+-----+----+" << std::endl;  
    std::cout << "\t\t\t\t| " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << " |" << std::endl;  
    std::cout << "\t\t\t\t+----+-----+----+" << std::endl;  
    std::cout << "\t\t\t\t| " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << " |" << std::endl;
    std::cout << "\t\t\t\t+----+-----+----+" << std::endl;    
    std::cout << "\t\t\t\t| " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << " |" << std::endl;  
    std::cout << "\t\t\t\t+----+-----+----+" << std::endl;  
    std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << "+----+----+----+" << std::endl;
    // for(int i=0; i<GRID_SIZE; i++) {
    //     for(int j=0; j<GRID_SIZE; j++) {
            
    //         if(i == current_row && j == current_col) {
    //             std::cout << "| " << BLACK_TEXT << WHITE_BACKGROUND << grid[i][j] << " " RESET << " ";
    //         } else {
    //             std::cout << "| " << grid[i][j] << "  ";
    //         }
    //     }
    //     std::cout << "|" << std::endl;
    //     std::cout << "+----+----+----+" << std::endl;  
    // }
}
/**
 * The function "place" takes in the coordinates (x, y) and a boolean value "turn" and updates the grid
 * with either 'X' or 'O' depending on the value of "turn".
 * 
 * @param x The x parameter represents the x-coordinate of the position where the player wants to place
 * their symbol (either 'X' or 'O') on the grid.
 * @param y The y parameter represents the vertical position or column index in the grid where the
 * player wants to place their symbol (either 'X' or 'O').
 * @param turn The "turn" parameter is a boolean value that indicates whose turn it is to place a
 * symbol on the grid. If "turn" is true, it means it is player X's turn, and if "turn" is false, it
 * means it is player O's turn.
 */
void place(int x, int y, bool turn) {
    if(turn) { grid[x][y] = 'X'; } 
    else { grid[x][y] = 'O'; }
}
/**
 * The move function updates the current row and column based on the arrow key input and then displays
 * the updated grid.
 * 
 * @param arrowKey The arrowKey parameter is a character that represents the arrow key pressed by the
 * user. It can have one of the following values:
 */
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
    displayGrid(current_row, current_col);
}
/**
 * The function allows the player to make moves by reading keyboard input and updating the game state
 * accordingly.
 */
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
    displayGrid(current_row, current_col);
}
/**
 * The function "computerMove" generates random coordinates for the computer's move and places it on
 * the grid if the cell is empty.
 */
void computerMove() {
    int row;
    int col;
    srand(time(0));
    while(true) {
        row = rand() % 9;
        col = rand() % 9;
        if(grid[row][col] == ' ') {
            Sleep(1);
            place(row, col, yourTurn);
            break; // if player plays his move, end the while loop....
        }
    }
    place(row, col, yourTurn);
    yourTurn = true; // invert player turn to "player"....
}
/**
 * The function checks if there is a winner in a tic-tac-toe game and prints the result.
 * 
 * @param grid The parameter `grid` is a 2-dimensional character array representing the tic-tac-toe
 * grid. It has a size of `GRID_SIZE` by `GRID_SIZE`.
 * 
 * @return a boolean value. It returns true if there is a winner in the tic-tac-toe grid, and false
 * otherwise.
 */
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
/**
 * The function checks if there are any empty spaces left in the grid and returns true if there are
 * none, indicating a tie.
 * 
 * @param grid The parameter "grid" is a 2-dimensional character array representing the game grid. It
 * has a size of GRID_SIZE x GRID_SIZE, where GRID_SIZE is a constant representing the size of the
 * grid. Each element of the array represents a cell in the grid and can have one of three values:
 * 
 * @return a boolean value. If there are no more empty spaces in the grid, it returns true indicating a
 * tie. Otherwise, it returns false indicating that there are still empty spaces remaining.
 */
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