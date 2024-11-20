#include"game.h"
#include<stdio.h>
void Board(char add[ROW][COL], int row, int col)//定义函数
{
	for (int i = 0;i < row;i++)//初始化棋盘
	{
		for (int j = 0;j < col;j++)
		{
			add[i][j] = ' ';
		}
	
    }

}


void DisplayBoard(char add[ROW][COL], int row, int col)//创建棋盘
{
	for (int i = 0;i < row;i++)//创造行数
	{
		int j = 0;
		for (j = 0;j < col;j++)//创造列数
		{
			printf(" %c ", add[i][j]);//有空格，对齐格式
			if (j < col - 1)
			{
				printf("|");
			}

		}
		printf("\n");//换行都算一组
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}

}

void Playermove(char add[ROW][COL], int row, int col)//玩家移动
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("玩家请输入坐标:");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (add[x - 1][y - 1] == ' ')//判断是否被占用
			{
				add[x - 1][y - 1] = '*';
				break;//防止玩家输入错误
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
}

void Computermove(char add[ROW][COL], int row, int col)//电脑移动
{
	while (1)
	{
		
		int x = rand() % row;//控制
		int y = rand() % col;
		if (add[x][y] == ' ')
		{
			add[x][y] = '#';
			break;
		}
	}
}

int Isfull(char add[ROW][COL], int row, int col)//判断是否满了
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (add[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


char Ifwin(char add[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)//判断行
	{
		if (add[i][0] == add[i][1] && add[i][1] == add[i][2] && add[i][1] != ' ')
		{
			return add[i][1];
		}
	}
	for (int j = 0;j < col;j++)//判断列
	{
		if (add[0][j] == add[1][j] && add[1][j] == add[2][j] && add[1][j] != ' ')
		{
			return add[1][j];
		}

	}
	
	if (add[0][0] == add[1][1] && add[1][1] == add[2][2] && add[0][0] != ' ')//判断对角线
	{
		return add[0][0];
	}
	if (add[0][2] == add[1][1] && add[1][1] == add[2][0] && add[0][2] != ' ')
	{
		return add[0][2];
	}
	//判断平局
	//满了返回1，不满返回0
	int ret = Isfull(add, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return 'c';
}