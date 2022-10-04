#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define count_mine 10

void initboard(char board[ROWS][COLS], int rows, int cols, char set);
void disboard(char board[ROWS][COLS], int rows, int cols);
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int countmine(char board[ROWS][COLS], int x, int y);
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *win);
void show_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);