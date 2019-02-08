#pragma once

struct MItem				// ��� ������ ������ �������� ����
{
	char *Text;				// ����� ������� �������� ����
	int Length;				// ����� ������ �������� ����
	int Pos;				// ���������� � ��������� �� ������ ������ �������� ����
};

struct Menu					// ��� ������ Menu
{
	int X,					// ���������� � �������� ������ ���� ����
		Y,					// ���������� Y �������� ������ ���� ����
		CCount,				// ���������� �������� ����
		TabType;			// ��� ����� ����� ���� (0 - ���������; 1 - �������)
	bool Horizont;			// True - �������������� ����: False - ������������
	int Item;				// ����� ��������� ������� ���� (���������� � 0)
	short NormColors,		// �������� ��������� �� ��������� ����� (��. MyCrt)
		  SelectColors;		// �������� ��������� ��������� ������ (��. MyCrt)
	MItem *Items;			// ������ ����� ������ ����
	int MenuWidth,			// ��������� ���� - ������ ���� �� ������
	    MenuHeight;			// ��������� ���� - ������ ���� �� ������
	char *Buf;				// ��������� �� ����� ��� ���������� ����������� ��� ����
};

void InitMenu(				// ������������� ���������� ���� �
	Menu &T,				// ���������� ��� ����
	int X, int Y,			// ���������� � � Y �������� ������ ���� ����
	int TabType,			// ��� ����� ����� ���� (0 - ���������; 1 - �������)
	bool Horizont,			// True - �������������� ����: False - ������������
	short NormColors,		// �������� ��������� �� ��������� ������ (��. MyCrt)
	short SelectColors,		// �������� ��������� ��������� ������� (��. MyCrt)
	int n, int m,			// ����������� ���������� ������� Data[n][m]
	char *Data
	); 
void HideMenu(Menu T, short Colors);					// ������� ���� � ������ ������ Colors
void Show_Menu(Menu T);									// �������� ���� �� ������		
void FreeMenu(Menu &T, short Colors);					// ���������� ���� � ������ � �� ������
void DrawEmptyMenu(Menu T);								// ���������� ���� ��� ������ �� ������
void FillMenu(Menu T);									// ��������� ���� ��������� �� ������� ������
bool ItemChoice(Menu &T);								// ����� ������� ����

