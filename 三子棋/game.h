#pragma once
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//���ŵĶ���
#define COL 3   //��
#define ROW 3   //��


//����������
void Board(char add[ROW][COL], int row, int col);

void DisplayBoard(char add[ROW][COL], int row, int col);//��ӡ����

void Playermove(char add[ROW][COL], int row, int col);//����ƶ�

char Ifwin(char add[ROW][COL], int row, int col);//�жϽ��

void Computermove(char add[ROW][COL], int row, int col);//�����ƶ�