#pragma once
#include "atltypes.h"
class ChessNode
{
public:
	ChessNode(void);
	~ChessNode(void);
	
	ChessNode(CPoint chesspos, int chesstype);//���صĹ��캯��
	
	CPoint v_ChessPos;// �洢����λ��
	int v_ChessType;  // ������������
};

