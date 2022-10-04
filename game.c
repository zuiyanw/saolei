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
	for (i = 0; i <= col; i++)//��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//��ӡ�к�
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
	int count = count_mine;//�׵ĸ���
	while (count)
	{
		x = rand() % row + 1;//һ��������nȡģ���Ϊ 0-n-1
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
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//���������ñ߽�
	{
		int count2 = countmine(mine, x, y);//�ж��׵ĸ���
		if (count2 == 0)//��Χ�׵ĸ���Ϊ0
		{
			system("cls");
			show[x][y] = ' ';//�������Ϊ�ո� Ȼ������չ����Χ�ĸ���
			disboard(show, ROW, COL);
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')//��ʱshow[x][y]=' '   ��*������ɸѡ��show[x][y]
					{
						expand(mine,show, i, j, win);
					}	//�ⲿ��win����ʱ��Ҫ����ȡ��ַ���ڲ������ݹ�ʱ��win�Ѿ��ǵ�ַ�ˣ���Ҫ��ȡ��ַ�ˡ�
				}
			}
		}
		else
		{
			show[x][y] = count2 + '0';//����ת��Ϊ�ַ�
			system("cls");
			disboard(show, ROW, COL);
		}
		(*win)++;
	}
}
int countmine(char board[ROWS][COLS], int x, int y)//��x��yΧ���� һȦ�׵ĸ���
{
	return board[x - 1][y - 1] + board[x - 1][y] +
		board[x - 1][y + 1] + board[x][y - 1] +
		board[x][y + 1] + board[x + 1][y - 1] +
		board[x + 1][y] + board[x + 1][y + 1]-8*'0';
}
void show_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//��show�еĵ��׸ı����
{
	int i = 0;
	for (i = 1; i <= row; i++)
	{
		int j = 0;
		for (j = 1; j <= COL; j++)
		{
			if (mine[i][j] == '1')
			{
				show[i][j] = '@';    //�����׸ĳ� '@'
			}
		}
	}
	disboard(show, row, col);   //��ӡ
}
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;//winΪ��������-���׵ĸ���
	printf("������һ�����꣺\n");
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
						printf("��ȵ������ˣ���Ϸ����\n");
						show_mine(mine, show, row, col);
						break;
					}
					else
					{
						int count2 = countmine(mine, x, y);//������Χ���׸���
						expand(mine, show, x, y, &win);//չ���ݹ麯�� ��Χ�����ǵ��׵Ļ� �������Ϊ' '
					}	//�ⲿ��win����ʱ��Ҫ����ȡ��ַ���ڲ������ݹ�ʱ��win�Ѿ��ǵ�ַ�ˣ���Ҫ��ȡ��ַ�ˡ�
				}
				else
				{
					printf("����������");
				}
			}
			else
			{
				printf("���������������룺\n");
			}
	}
	if (win == row*col - count_mine)
	{
		printf("ɨ�׳ɹ�\n");
		show_mine(mine, show, row, col);
	}
}