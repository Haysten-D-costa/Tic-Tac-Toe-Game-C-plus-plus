#include <iostream>
#include <conio.h>
#include <ctime>
#include "textstyling.h"

#define GRID_SIZE 3

int control = 0; // by default, grid1 is active....
int current_row = 0;
int current_col = 0;
static int counter = 0;
enum grids {grid1, grid2, grid3, grid4, grid5, grid6, grid7, grid8, grid9};

char grid01[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid02[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid03[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid04[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid05[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid06[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid07[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid08[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid09[GRID_SIZE][GRID_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void move(char arrowKey);
void playerMove(char grid[GRID_SIZE][GRID_SIZE]);
void display(int current_row, int current_col, int control);
void place(int x, int y, bool turn, char grid[GRID_SIZE][GRID_SIZE]);

int main() { // ! MAIN FUNCTION START !.....
    
    while(true) {
        display(0, 0, control);
        // int key = _getch();
        playerMove(grid01);
        
    }
    return 0;
} // ! MAIN FUNCTION END !.....

void place(int x, int y, bool turn, char grid[GRID_SIZE][GRID_SIZE]) {
    if(turn) { grid[x][y] = 'X'; } 
    else { grid[x][y] = 'O'; }
}
void move(char arrowKey) {
    if (arrowKey == 72 && current_row > 0) { current_row--; } 
    else if (arrowKey == 80 && current_row < GRID_SIZE - 1) { current_row++; } 
    else if (arrowKey == 75 && current_col > 0) { current_col--; } 
    else if (arrowKey == 77 && current_col < GRID_SIZE - 1) { current_col++; }
    display(current_row, current_col, control);
}
void playerMove(char grid[GRID_SIZE][GRID_SIZE]) {
    while(true) {
        int key = _getch();
        if((key == 72) || (key == 80) || (key == 75) || (key == 77)) { move(key); }
        else if((key == 13)) { 
            place(current_row, current_col, true, grid);
            break; // if player selects a spot, end the while loop....
        }
    }
}
void display(int current_row, int current_col, int control) { // Function displays all the grids....
    system("cls");
    std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid1) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid01[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid01[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid2) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid02[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid02[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid3) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid03[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid03[i][j] << "  ";
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;  
    }
    std::cout << std::endl;
    std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid4) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid04[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid04[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid5) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid05[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid05[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid6) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid06[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid06[i][j] << "  ";
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;  
    }
    std::cout << std::endl;
    std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid7) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid07[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid07[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid8) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid08[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid08[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<GRID_SIZE; j++) {
            if(i == current_row && j == current_col && control == grid9) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid09[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid09[i][j] << "  ";
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;  
    }
}
