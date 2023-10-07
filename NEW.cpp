/*
    x -> row, y -> col....
*/
#include <iostream>
#include <conio.h>
#include <ctime>
#include "textstyling.h"

#define MAX 3

int x = 0;
int y = 0;
int control = 0;
bool count = true;
char grid01[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid02[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid03[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid04[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid05[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid06[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid07[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid08[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char grid09[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void playerMove(char player);
void display(); // function definition....
void place(char player);
void storeControl();

void storeControl() {
    if ((x == 0) && (y == 0)) { control = 0; }
    else if ((x == 0) && (y == 1)) { control = 1; }
    else if ((x == 0) && (y == 2)) { control = 2; }
    else if ((x == 1) && (y == 0)) { control = 3; }
    else if ((x == 1) && (y == 1)) { control = 4; }
    else if ((x == 1) && (y == 2)) { control = 5; }
    else if ((x == 2) && (y == 0)) { control = 6; }
    else if ((x == 2) && (y == 1)) { control = 7; }
    else if ((x == 2) && (y == 2)) { control = 8; }
}
void place(char player) {
    count = false; // to disable the 'tab' functionality, after player plays his first move....
    
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

    if(player == 'X') {
        if(ptr[x][y] == ' ') {
            ptr[x][y] = 'X';
            storeControl();
        }
    } 
    else { 
        if(ptr[x][y] == ' ') { 
            ptr[x][y] = 'O'; 
            storeControl();
        }
    }
}
void playerMove(char player) {
    int key;
    while(true) {
        display();
        key = _getch();
        if(key == 27) { system("cls"); exit(1); } // escape key, to exit....
        if(count == true && key == 9) { // tab key, to switch table....
            control++;
            if(control == 9) { control = 0; } 
        }
        else if(key == 72 && x > 0) { x--; }
        else if(key == 80 && x < MAX-1) { x++; }
        else if(key == 75 && y > 0) { y--; }
        else if(key == 77 && y <MAX-1) { y++; }
        else if(key == 13) {  // enter key, to make a move....
            if(player == 'X') { 
                place( 'X');
                break; // after player makes a move, exit the while loop....
            }
            else { 
                place('O');
                break; // after player makes a move, exit the while loop....
            }
        }
        // std::cout << "HERE 2";system("pause"); 
        // display(x, y, control);
    }
}
void display() { // Function displays all the grids....
    system("cls");
    std::cout << "+----+----+----+    +----+----+----+    +----+----+----+" << std::endl;
    for(int i=0; i<MAX; i++) {
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 0) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid01[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid01[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 1) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid02[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid02[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 2) {
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
            if(i == x && j == y && control == 3) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid04[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid04[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 4) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid05[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid05[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 5) {
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
            if(i == x && j == y && control == 6) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid07[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid07[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 7) {
                std::cout << "| " << HIGHLIGHT << BLACK_TEXT << WHITE_BACKGROUND << grid08[i][j] << " " RESET << " ";
            } else {
                std::cout << "| " << grid08[i][j] << "  ";
            }
        }
        std::cout << "|    ";
        for(int j=0; j<MAX; j++) {
            if(i == x && j == y && control == 8) {
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
        playerMove('X');
        playerMove('O');
    }
    return 0;
}
