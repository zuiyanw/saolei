#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand() srand()���õ�ͷ�ļ�
#include <time.h>  //time���õ�ͷ�ļ�
#define ROW 9
#define COL 9

#define ROWS ROW+2 
#define COLS COL+2

#define count_mine 80//��3����

void initboard(char board[ROWS][COLS], int rows, int cols, char set);
void disboard(char board[ROWS][COLS], int rows, int cols);
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char board[ROWS][COLS], int row, int col);
int summine(char mine[ROWS][COLS], int row, int col);