#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("***********************\n");
	printf("***     1.play    *****\n");
	printf("***     0.exit    *****\n");
	printf("***********************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	initboard(mine, ROWS, COLS, '0');//棋盘初始化
	initboard(show, ROWS, COLS, '*'); 
	//disboard(mine, ROW, COL);//打印函数
	disboard(show, ROW, COL);
	printf("\n");
	setmine(mine,ROW,COL);//设置雷
	disboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);//
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	do
	{
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新选择：\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}