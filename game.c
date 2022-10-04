#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
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
	for (i = 0; i <= col; i++)//打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//打印行号
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
	int count = count_mine;//雷的个数
	while (count)
	{
		x = rand() % row + 1;//一个整数对n取模结果为 0-n-1
		y = rand() % col + 1;
		if (x >=1 && x <= row && y>=1 && y <= col)
		{
			if (board[x][y] == '0')
			{
				board[x][y] = '1';
				count--;//count=10--
			}
		}
	}
}
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *win)
{
	int i = 0;
	int j = 0;
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//给棋盘设置边界
	{
		int count2 = countmine(mine, x, y);//判断雷的个数
		if (count2 == 0)//周围雷的个数为0
		{
			system("cls");
			show[x][y] = ' ';//坐标输出为空格 然后依次展开周围的格子
			disboard(show, ROW, COL);
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')//此时show[x][y]=' '   ‘*’用来筛选掉show[x][y]
					{
						expand(mine,show, i, j, win);
					}	//外部传win参数时需要进行取地址，内部函数递归时，win已经是地址了，不要再取地址了。
				}
			}
		}
		else
		{
			show[x][y] = count2 + '0';//数字转换为字符
			system("cls");
			disboard(show, ROW, COL);
		}
		(*win)++;
	}
}
int countmine(char board[ROWS][COLS], int x, int y)//以x，y围中心 一圈雷的个数
{
	return board[x - 1][y - 1] + board[x - 1][y] +
		board[x - 1][y + 1] + board[x][y - 1] +
		board[x][y + 1] + board[x + 1][y - 1] +
		board[x + 1][y] + board[x + 1][y + 1]-8*'0';
}
void show_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//将show中的地雷改变符号
{
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= COL; j++)
		{
			if (mine[i][j] == '1')
			{
				show[i][j] = '@';    //将地雷改成 '@'
			}
		}
	}
	disboard(show, row, col);   //打印
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//win为棋子总数-布雷的个数
	printf("请输入一个坐标：\n");
	while (win < row*col - count_mine)
	{
		scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (show[x][y] == '*')
				{
						if (mine[x][y] == '1')
					{
						system("cls");
						printf("你踩到地雷了，游戏结束\n");
						show_mine(mine, show, row, col);
						break;
					}
					else
					{
						int count2 = countmine(mine, x, y);//计算周围地雷个数
						expand(mine, show, x, y, &win);//展开递归函数 周围都不是地雷的话 该坐标改为' '
					}	//外部传win参数时需要进行取地址，内部函数递归时，win已经是地址了，不要再取地址了。
				}
				else
				{
					printf("请重新输入");
				}
			}
			else
			{
				printf("输入错误，请从新输入：\n");
			}
	}
	if (win == row*col - count_mine)
	{
		printf("扫雷成功\n");
		show_mine(mine, show, row, col);
	}
}