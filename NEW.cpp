/*
    x -> row, y -> col....
*/
#include <iostream>
#include <conio.h>
#include <ctime>
#include "textstyling.h"

#define MAX 3

int control = 0;
char grid01[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x1 = 0, y1 = 0;
char grid02[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x2 = 0, y2 = 0;
char grid03[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x3 = 0, y3 = 0;
char grid04[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x4 = 0, y4 = 0;
char grid05[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x5 = 0, y5 = 0;
char grid06[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x6 = 0, y6 = 0;
char grid07[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x7 = 0, y7 = 0;
char grid08[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x8 = 0, y8 = 0;
char grid09[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; int x9 = 0, y9 = 0;

void playerMove(int x, int y, char player);
void display(int x, int y, int control); // function definition....
void place(int x, int y, int control, char player);


void place(int x, int y, int control, char player) {
    
    char(* ptr)[MAX]; // character pointer created, to access specific grids....
    if(control == 0) { ptr = grid01; } // point to specific grids, as per the control....
    else if(control == 1) { ptr = grid02; }
    else if(control == 2) { ptr = grid03; }
    else if(control == 3) { ptr = grid04; }
    else if(control == 4) { ptr = grid05; }
    else if(control == 5) { ptr = grid06; }
    else if(control == 6) { ptr = grid07; }
    else if(control == 7) { ptr = grid08; }
    else if(control == 8) { ptr = grid09; }

    if(player == 'X') { ptr[x][y] = 'X'; } 
    else {ptr[x][y] = 'O'; }
}
void playerMove(int x, int y, char player) {
    int key;
    while(true) {
        display(x, y, control);
        key = _getch();
        if(key == 9) { 
            control++;
            if(control == 9) { control = 0; } 
        }
        else if(key == 72 && x > 0) { x--; }
        else if(key == 80 && x < MAX-1) { x++; }
        else if(key == 75 && y > 0) { y--; }
        else if(key == 77 && y <MAX-1) { y++; }
        else if(key == 13) { 
            if(player == 'X') { place(x, y, control, 'X'); }
            else { place(x, y, control, 'O'); }
        }
        // break;
        if(player == 'X') { player = 'O'; }
        else { player = 'X'; }
    }
}
void display(int current_row, int current_col, int control) { // Function displays all the grids....
    system("cls");
    std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 0) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid01[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid01[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 1) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid02[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid02[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 2) {
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
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 3) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid04[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid04[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 4) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid05[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid05[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 5) {
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
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 6) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid07[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid07[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 7) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid08[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid08[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == current_row && j == current_col && control == 8) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid09[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid09[i][j] << "  ";
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;  
    }
}
int main() {
    while(true) {
        playerMove(0, 0, 'X');
    }
    return 0;
}