#include"game.h"
#include<stdio.h>
void Board(char add[ROW][COL], int row, int col)//���庯��
{
	for (int i = 0;i < row;i++)//��ʼ������
	{
		for (int j = 0;j < col;j++)
		{
			add[i][j] = ' ';
		}
	
    }

}


void DisplayBoard(char add[ROW][COL], int row, int col)//��������
{
	for (int i = 0;i < row;i++)//��������
	{
		int j = 0;
		for (j = 0;j < col;j++)//��������
		{
			printf(" %c ", add[i][j]);//�пո񣬶����ʽ
			if (j < col - 1)
			{
				printf("|");
			}

		}
		printf("\n");//���ж���һ��
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

void Playermove(char add[ROW][COL], int row, int col)//����ƶ�
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("�������������:");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (add[x - 1][y - 1] == ' ')//�ж��Ƿ�ռ��
			{
				add[x - 1][y - 1] = '*';
				break;//��ֹ����������
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

void Computermove(char add[ROW][COL], int row, int col)//�����ƶ�
{
	while (1)
	{
		
		int x = rand() % row;//����
		int y = rand() % col;
		if (add[x][y] == ' ')
		{
			add[x][y] = '#';
			break;
		}
	}
}

int Isfull(char add[ROW][COL], int row, int col)//�ж��Ƿ�����
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
	for (int i = 0;i < row;i++)//�ж���
	{
		if (add[i][0] == add[i][1] && add[i][1] == add[i][2] && add[i][1] != ' ')
		{
			return add[i][1];
		}
	}
	for (int j = 0;j < col;j++)//�ж���
	{
		if (add[0][j] == add[1][j] && add[1][j] == add[2][j] && add[1][j] != ' ')
		{
			return add[1][j];
		}

	}
	
	if (add[0][0] == add[1][1] && add[1][1] == add[2][2] && add[0][0] != ' ')//�ж϶Խ���
	{
		return add[0][0];
	}
	if (add[0][2] == add[1][1] && add[1][1] == add[2][0] && add[0][2] != ' ')
	{
		return add[0][2];
	}
	//�ж�ƽ��
	//���˷���1����������0
	int ret = Isfull(add, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	else
		return 'c';
}