#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows;i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void disboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//行列的下标从1开始
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = count_mine;
	while (count)//count=0时，跳出循环
	{
		x = rand() % row + 1;//rand()%row=1~8 一个整数对n取模的结果范围为： 0 到n− 1,
		y = rand() % col + 1;
		if (board[x][y] == '0')//
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int summine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x][y + 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	int count = 0;
	printf("请输入一个坐标：\n");//用户输入坐标
	while (win<ROW*COL-count_mine)//9*9的棋盘上 有10个雷的话 剩下71个格子不是雷
	{
		scanf("%d%d", &x, &y);
		int count = summine(mine, x, y);//计算mine数组 坐标x,y周围的地雷总和 '1'-'0'=1
		if (x > 0 && x <= row && y > 0 && y <= row)
		{
			if (mine[x][y] == '1')//初始棋盘为11*11 所以9*9的棋盘
			{
				printf("踩到地雷，游戏失败\n");
				disboard(mine, row, col);//将地雷打印一遍 让玩家知道雷的位置 这里因为是已经在穿过实参的函数中了 上传小写row col
				break;
			}
			else     //如果不是雷 坐标显示的是字符'0' 计算周围8个方块中雷的个数
			{
				dgmine();
				show[x][y] = count + '0';
				disboard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入错误，请重新输入：\n");
		}
	}
	if (win == ROW*COL - count_mine)
	{
		printf("恭喜你，排雷成功\n");
		disboard(show, row, col);
	}
}