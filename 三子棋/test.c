#include<stdio.h>
#include"game.h"
void menu()//菜单
{
	printf("**************************\n");
	printf("******   1.play      *****\n");
	printf("******   0.exit      *****\n");
	printf("**************************\n");


}
void game()//游戏函数
{
	char ret = 0;//储存比赛结果
	char add[ROW][COL];//储存数据，二维数组
	Board(add, ROW, COL);//初始化棋盘
	Sleep(1000);
	system("cls");
	Sleep(1000);
		DisplayBoard(add, ROW, COL);//打印n*n的棋盘
		while (1)
		{
			printf("玩家请走\n");
			Playermove(add, ROW, COL);//玩家移动
			DisplayBoard(add, ROW, COL);
			ret = Ifwin(add, ROW, COL);//判断是否嬴
			if (ret != 'c')
				break;

			Computermove(add, ROW, COL);//电脑移动
			system("cls");
			printf("电脑走：\n");
			DisplayBoard(add, ROW, COL);
			ret = Ifwin(add, ROW, COL);//判断
			if (ret != 'c')
				break;//跳出结果
		}
		if (ret == '*')
			printf("玩家赢啦！！！\n");
		if (ret == '#')
			printf("电脑赢了！！！\n");
		if(ret=='Q')
			printf("平局哟，继续加油\n");
		
}


int main()//主函数
{
	srand((unsigned int)time(NULL));
	int input = 0;
	int ret = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏开始!!!!\n");
			game();
			break;
		case 0:
			printf("欢迎下次光临！！！\n");
			break;
		default:
			printf("选择错误，请重新选择！！！\n");

		}

	} while (input);


	return 0;
}