#include "StdAfx.h"
#include "Includes.h"
#include "ChessNode.h"


ChessNode::ChessNode(void)
	: v_ChessPos(0)
	, v_ChessType(0)
{
}


ChessNode::~ChessNode(void)
{
}


ChessNode::ChessNode(CPoint chesspos, int chesstype)
{
	v_ChessPos  = chesspos;
	v_ChessType = chesstype;
}
