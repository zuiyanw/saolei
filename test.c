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
	char mine[ROWS][COLS] = { 0 };//ԭʼ���̷��ַ�0
	char show[ROWS][COLS] = { 0 };//չʾ���̷��ַ�*
	initboard(mine, ROWS, COLS, '0');//���̳�ʼ�� ע���������ַ�'0'
	initboard(show, ROWS, COLS, '*');
	//disboard(mine, ROW, COL);//��ӡ���� ��Ϊ��ӡ����9*9���Ǹ����� �������ﴫ��ʵ����ROW COL
	//printf("\n");
	disboard(show, ROW, COL);
	setmine(mine, ROW, COL);//������
	disboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);//��mine��������ϢȻ�����show�����У�����ֻ��9*9�в��� 
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������,������ѡ��\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}