#pragma once
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//符号的定义
#define COL 3   //列
#define ROW 3   //行


//函数的声明
void Board(char add[ROW][COL], int row, int col);

void DisplayBoard(char add[ROW][COL], int row, int col);//打印棋盘

void Playermove(char add[ROW][COL], int row, int col);//玩家移动

char Ifwin(char add[ROW][COL], int row, int col);//判断结果

void Computermove(char add[ROW][COL], int row, int col);//电脑移动