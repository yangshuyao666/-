#include<stdio.h>
#include"game.h"
void menu()//�˵�
{
	printf("**************************\n");
	printf("******   1.play      *****\n");
	printf("******   0.exit      *****\n");
	printf("**************************\n");


}
void game()//��Ϸ����
{
	char ret = 0;//����������
	char add[ROW][COL];//�������ݣ���ά����
	Board(add, ROW, COL);//��ʼ������
	Sleep(1000);
	system("cls");
	Sleep(1000);
		DisplayBoard(add, ROW, COL);//��ӡn*n������
		while (1)
		{
			printf("�������\n");
			Playermove(add, ROW, COL);//����ƶ�
			DisplayBoard(add, ROW, COL);
			ret = Ifwin(add, ROW, COL);//�ж��Ƿ���
			if (ret != 'c')
				break;

			Computermove(add, ROW, COL);//�����ƶ�
			system("cls");
			printf("�����ߣ�\n");
			DisplayBoard(add, ROW, COL);
			ret = Ifwin(add, ROW, COL);//�ж�
			if (ret != 'c')
				break;//�������
		}
		if (ret == '*')
			printf("���Ӯ��������\n");
		if (ret == '#')
			printf("����Ӯ�ˣ�����\n");
		if(ret=='Q')
			printf("ƽ��Ӵ����������\n");
		
}


int main()//������
{
	srand((unsigned int)time(NULL));
	int input = 0;
	int ret = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ��ʼ!!!!\n");
			game();
			break;
		case 0:
			printf("��ӭ�´ι��٣�����\n");
			break;
		default:
			printf("ѡ�����������ѡ�񣡣���\n");

		}

	} while (input);


	return 0;
}