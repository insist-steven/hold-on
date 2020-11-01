#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2
int const Easy = 10;

void initarray(char array[ROWS][COLS], int rows, int cols, char set);
void displayarray(char array[ROWS][COLS], int row, int col);
void wriarray(char array[ROWS][COLS], int row, int col);
void findarray(char main[ROWS][COLS], char show[ROWS][COLS], int row, int col);