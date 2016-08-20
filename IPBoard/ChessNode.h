#pragma once
#include "atltypes.h"
class ChessNode
{
public:
	ChessNode(void);
	~ChessNode(void);
	
	ChessNode(CPoint chesspos, int chesstype);//重载的构造函数
	
	CPoint v_ChessPos;// 存储棋子位置
	int v_ChessType;  // 填充的棋子类型
};

