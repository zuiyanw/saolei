#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("******************\n");
	printf("***  1.play  *****\n");
	printf("***  2.exit  *****\n");
	printf("******************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//原始棋盘放字符0
	char show[ROWS][COLS] = { 0 };//展示棋盘放字符*
	initboard(mine, ROWS, COLS, '0');//棋盘初始化 注意这里是字符'0'
	initboard(show, ROWS, COLS, '*');
	//disboard(mine, ROW, COL);//打印棋盘 因为打印的是9*9的那个棋盘 所以这里传的实参是ROW COL
	//printf("\n");
	disboard(show, ROW, COL);
	setmine(mine, ROW, COL);//布置雷
	disboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);//在mine数组找信息然后放在show数组中，操作只在9*9中操作 
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新选择：\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}