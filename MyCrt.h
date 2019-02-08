#pragma once;

#include <Windows.h>

struct sKeyCode {
	wchar_t kc, sc;
};

struct sMouseInf {
	char mState;
	int x, y;
};

union uKeyOrMouseInf {
	sKeyCode KeyCode;
	sMouseInf MouseInf;
};

short MaxX();  // ���������� ������ ������ ������
short MaxY();  // ���������� ������ ������ ������
void ConWidth(int W);  // ������������� ������ W ������ ������
void ConHeight(int H); // ������������� ������ H ������ ������
void ConSize(int W, int H); // ������������� ������ W � ������ H ������ ������
void ScrollVert(int P); // ���������� ���� ������� �� ��������� �� � ����� (��� � > 0 - ����; ��� � < 0 - �����)
void ScrollHor(int P); // ���������� ���� ������� �� ����������� �� � ������� (��� � > 0 - ������; ��� � < 0 - �����)
int GetScrWidth(); // ���������� ������ ���� �������
int GetScrHeight(); // ���������� ������ ���� �������
void ScrSize(int W, int H); // ������������� ������ W � ������ H ���� �������
void ScrGoTo(int X, int Y); // ���������� ���� ������� � ����� ������ ������ � ������������ (X, Y)
void CursorVisible(bool Visible); // �������� � ��������� ��������� ������� � ���� �������
void GoToXY(short x, short y); // ���������� ������ � ����� ������ ������� � ������������ (X, Y)
unsigned short WhereX(); // ���������� ���������� � �������� ��������� �������
unsigned short WhereY(); // ���������� ���������� Y �������� ��������� �������
void WhereXY(unsigned short &x, unsigned short &y); // ���������� ���������� � � Y �������� ��������� �������
unsigned short GetTextColors(); // ���������� �������� ��������� ������ ������ � ����������������� �������
void TextBackground(unsigned short Color); // ������������� ���� ����
void TextForeground(unsigned short Color); // ������������� ���� ��������
void TextColor(unsigned short Colors); // ������������� ����� ���� � �������� 
// �������� �������� ��������� �� Colors ������� � ����� � ������������ (X, Y) �� ������� ������ len ��������
void ChangeTextAttribute(unsigned short Colors, unsigned short x, unsigned short y, unsigned short len);
void ClrScr(); // ������� ������ ������ ������� ������������� ������ ���� 
void FillChar(int x, int y, int len, char c); // ������� � ����� (X, Y) ������� len ��� ������ �
void FillChar(int x, int y, int len, char c, short Colors); // ������� � ����� (X, Y) ������� len ��� ������ � ������� Colors
void FillChar(int x, int y, int len, wchar_t c); // ������� � ����� (X, Y) ������� len ��� ������ �
void FillChar(int x, int y, int len, wchar_t c, short Colors); // ������� � ����� (X, Y) ������� len ��� ������ � ������� Colors
void ClearEoln(); // ������� ������ �� ������� ������� ������� �� ����� ������
void WriteText(int x, int y, wchar_t s[]); // ������� ����� S � ����� � ������������ (X, Y)
void WriteText(int x, int y, wchar_t s[], short Colors); // ������� ����� S � ����� � ������������ (X, Y) � ������� Colors
void WriteText(int x, int y, char s[]); // ������� ����� S � ����� � ������������ (X, Y)
void WriteText(int x, int y, char s[], short Colors); // ������� ����� S � ����� � ������������ (X, Y) � ������� Colors
bool ReadKey(wchar_t &c); // ������������ ������ ���� � ������� �������. ���������� TRUE, ���� ������ ������� �������
bool ReadKey(char &c); // ������������ ������ ���� � ������� �������. ���������� TRUE, ���� ������ ������� �������
int ReadKeyOrMouse(uKeyOrMouseInf &KMF); // ������������ ������� ���������� � ����
bool CopyRect(int Left, int Top, int Right, int Bottom, char *Buffer);	// ���������� ������������� ������� ������ � �����
bool CopyRect(int Left, int Top, int Right, int Bottom, CHAR_INFO *Buffer);
bool PasteRect(int Left, int Top, int Right, int Bottom, char *Buffer); // ��������� ����������� ������������� ������� ������ �� ������ �� �����

void MessageDlg(int X, int Y, wchar_t *Text, int FrameType, short Colors);
	// ������������ ��������� ��������� Text ��������� � ���� � ������������ X � Y.
	// ������ ���� ������������� �������������� ��� ����� ������ ���������
	// ����� ��������� ����������� ��������� �������
void MessageDlg(int X, int Y, char *Text, int FrameType, short Colors);
	// ������������ ��������� ��������� Text ��������� � ���� � ������������ X � Y.
	// ������ ���� ������������� �������������� ��� ����� ������ ���������
	// ����� ��������� ����������� ������������ ��������� 
void MessageDlg(char *Text, int FrameType, short Colors);
	// ���� ��������� ������������� ����������� � ���� ����������
	// ������ ���� ������������� �������������� ��� ����� ������ ���������
	// ����� ��������� ����������� ������������ ���������
void MessageDlg(wchar_t *Text, int FrameType, short Colors);
	// ����� ��������� ����������� ��������� �������
	// ������ ���� ������������� �������������� ��� ����� ������ ���������
	// ���� ��������� ������������� ����������� � ���� ����������
void MessageDlg(int MaxLen, char *Text, int FrameType, short Colors);
	// ��������� Text ��������� � ����, ������ �������� ����� MaxLen
	// ������ ���� ������������� �������������� ��� ����� ������ ���������
	// ���� ��������� ������������� ������������ � ���� ����������
	// ����� ��������� ����������� ������������ ���������
bool YesNoDlg(int MaxLen, char *Text, int FrameType, short Colors, bool Def, bool &Esc);
	// ������ Text ��������� � ����, ������ �������� ����� MaxLen
	// ������ ���� ������������� �������������� ��� ����� ������ �������
	// ���� ������� ������������� ����������� � ���� ����������
	// ����� ������� ����������� ������������ ���������
	// ���������� ��������� ������ (true - false) � ����� �� ������ Esc (������� Escape) 
	// Def - �������� �������� ���������� ������
char *ReadLine(char *S, int len); 	// ������� ��� ����������� ����� � ���������� ������� ����

// �� ���� �������� �������� Colors ������ �������� ��������� ������ ������ � ����������������� �������.
// ��������: 0�1F - ���������� ��������� ����� 1 - ���� ���� (�����-�����), F - ���� �������� (����-�����)

