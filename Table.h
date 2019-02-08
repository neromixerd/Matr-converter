#pragma once

///////////////////////////////   �������   ///////////////////////////////

typedef double TInf;        // ��� ������ ��� ������� (��� ����� ����� �������� double �� int)

struct Table
{
	short
		X,					// ���������� � �������� ������ ���� �������
		Y,					// ���������� Y �������� ������ ���� �������
		CCount,				// ���������� �������� �������
		CWidth,				// ������ �������� ������� ��� ����� ������
		RCount,				// ���������� ����� �������
		RHeight,			// ������ ����� ������� ��� ����� ������
		TabType,			// ��� ����� ����� ������� (0 - ���������; 1 - �������; 2 - ���������������)
		Row,				// ������ ������ ��������� ������ ������ (������ ������ ����� ������ 0)
		Col,				// ������ ������� ��������� ������ ������ (������ ������� ����� ������ 0)
		Width,				// ������ ������� �������
		Height,				// ������ ������ �������
	    NormColors,		    // �������� ��������� �� ��������� ����� (��. MyCrt)
		SelectColors,		// �������� ��������� ��������� ������ (��. MyCrt)
		Precision;			// ���������� �������� ����� ���������� �����
	TInf Value;				// �������� � ��������� ������ ������
	union					// ������ ������ ��� ���������� ����� ������� 
	{
		TInf * Data;		
		TInf ** Data1;
	};
	bool TypeData;          // ��� ���������� �������: true - Data[i][j]; false - Data[i * Col + j]
	short DataRCount,		// ���������� ����� � ������� ������
		  DataCCount,		// ���������� �������� � ������� ������
		  DataRowTop,		// ������ ������ ������� ������, ����������� � ������ ������ �������
		  DataColLeft;		// ������ ������� ������� ������, ������������ � ������ ������� �������
	char *Buf;				// ��������� �� ����� ��� ���������� ����������� ��� ��������
    bool Headers;			// �������� ���������� ����� � ��������
    short RowHeaderWidth;   // ������ ������� ���������� �����
	bool Visible,			// ������� �� ������
	     ViewerShow;	    // �������� ����������� �������� �����
	bool ReadOnly;          // ��������� ��������������
    short EditorLen;		// ����� ������ ���������
};
void InitTable(Table &T, int X, int Y, int CCount, int CWidth, int RCount, int RHeight, int TabType, short NormColors, short SelectColors, TInf *Data, 
			   short DataCCount, short DataRCount, short Precision, bool ReadOnly, bool Viewer, bool Headers = true);      // ������������� ���������� ������� �
void InitTable(Table &T, int X, int Y, int CCount, int CWidth, int RCount, int RHeight, int TabType, short NormColors, short SelectColors, TInf **Data, 
			   short DataCCount, short DataRCount, short Precision, bool ReadOnly, bool Viewer, bool Headers = true);     // ������������� ���������� ������� �
void HideTable(Table &T, short Colors);					// ������� ������� � ������ ������ Colors
void ShowTable(Table &T);								// �������� ������� �� ������		
void DrawEmptyTable(Table &T);							// ���������� ������� ��� ������ �� ������
void FillTable(Table &T);								// ��������� ������� ������� �� ������� �������
char CellChoice(Table &T);								// ����� ������ �������
TInf GetValue(Table &T, int Row, int Col);				// ����� �������� ������ � ��������� Row, Col
TInf GetValue(Table &T);				                // ����� �������� �������� ������
void SetValue(Table &T, int Row, int Col, TInf Val);	// ������� �������� � ������ � ��������� Row, Col ������� �������
void SetValue(Table &T, TInf Val);		                // ������� �������� � �������� ������
void DrawValue(Table &T, int Row, int Col, TInf Val);	// ������� �������� � ������ � ��������� Row, Col ������� ������� � ������� �� �����
void DrawValue(Table &T, TInf Val);	                    // ������� �������� � �������� ������ ������� ������� � ������� �� �����
void FreeTable(Table &T);								// ������� � ������ � ����������� ������ �� �������
void EditValue(Table &T, char Ch);						// �������������� �������� ������� ������

/////////////////////////////////   ����    //////////////////////////////////

struct Frame
{
	int X,					// ���������� � �������� ������ ���� ����
		Y,					// ���������� Y �������� ������ ���� ����
		Height,				// ������
		Width,				// ������
		Type;				// ��� ����� ����� (-1 - ��� �����; 0 - ���������; 1 - �������)
	short Colors;			// �������� ��������� (��. MyCrt)
	char *Title;			// ����� ���������� ����
	char *Buf;				// ��������� �� ����� ��� ���������� ����������� ��� �����
};

void InitFrame(Frame &T, int X, int Y, int Width, int Height, int TabType, short Colors, char *Title); // ������������� ���������� ����
void HideFrame(Frame &T);					// ������ ���� � ������
void ShowFrame(Frame &T);					// �������� ���� �� ������		
void FreeFrame(Frame &T);					// ����������� ���� �� ������ � � ������
