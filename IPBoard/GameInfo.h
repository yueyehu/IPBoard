#pragma once
#include "atltypes.h"
#include "ChessNode.h"
#include "afxtempl.h"
class GameInfo:public CObject
{
	DECLARE_SERIAL(GameInfo);// 为类声明序列化

public:
	GameInfo(void);
	~GameInfo(void);

public:
	virtual void Serialize(CArchive &ar); //程序序列化函数

public:
	CPoint v_ViewSize;      // 客户端视图大小
	int v_PixelsPerFootX;   // 屏幕像素每英寸
	int v_PixelsPerFootY;   // 屏幕像素每英寸
	
	int v_BoardNumK;        // 算法中的k值
	int v_ChessPieceSize;   // 棋子的尺寸,由K值决定
	int v_BoardPieceNum;    // 每行棋子的数目
	CPoint v_OriginalPoint; // 坐标的起始位置，由K值和客户端视图大小决定
	
	CPoint v_IPPiecePos;    // 残缺棋子的位置
	int v_GameAutoFillTime; //游戏自动填充时间间隔

	CPoint v_FillPiecePos;  // 临时存储填充块坐标
	CArray<ChessNode,ChessNode> v_ChessList;// 用于存储填充块信息
	int *vp_PieceSign;      // 用于存储棋盘中的棋子是否填充的信息

	int v_PieceType;           // 放置的填充块类型，用于手动
	bool v_ManualOrAuto;       // 标识手动或者自动
	bool v_GameAutoUpdateSign; // 游戏自动更新
	bool v_UpdateSign;         // 更新标志
	int v_GameSaveSign;        // 游戏保存标志
	bool v_GameRunningSign;    // 游戏运行标志

	int v_GameAutoFillCount;   // 游戏自动填充的次数
	int v_Time;                // 游戏时间

public:
	void GameInit(void);     // 游戏初始化
	void GameOver(void);     // 游戏结束函数
	bool CheckGameOver(void);// 判断游戏是否结束
	void GameRestart(void);  // 游戏重新开始

	int GetBoardPieceNum(void);// 获取棋盘中每行的棋子数
	int GetBoardSize(void);    // 获取棋盘的尺寸

	void CreateSignArray(void);       // 动态创建数组
	int SetChessPieceSize(int metric);// 设置棋盘块尺寸
	void IPPieceInitial(void);        // 残缺棋子位置初始化
	
	void BoardDraw(CDC * pDC); // 绘制棋盘
	void IPPieceDraw(CDC *pDC);// 残缺棋子的绘制

	void FillChessDraw(CDC * pDC, ChessNode chessnode);// 绘制填充图
	void FillChessOneDraw(CDC * pDC,CPoint pos);       // 填充第一象限缺省棋子
	void FillChessTwoDraw(CDC * pDC,CPoint pos);       // 填充第二象限缺省棋子
	void FillChessThreeDraw(CDC * pDC,CPoint pos);     // 填充第三象限的缺省棋子
	void FillChessFourDraw(CDC * pDC,CPoint pos);      // 填充第四象限的缺省棋子

	CPoint ExchangeMousePixelToFoot(CPoint point);// 将像素转换为尺寸
	bool GetMouseBoardPos(CPoint point);          // 获取鼠标在棋盘中的位置
	bool CheckMouseDown(CPoint point);            // 判断鼠标点击是否有效
	bool CheckFillChess(ChessNode chessnode);     // 判断将要填充块是否冲突
	
	void AddChessInfo(ChessNode chessnode);// 保存填充块信息
	
	void GameAutoFill();               // 游戏自动填充
	void GameAutoFillOne(CPoint point);// 填充一次即可完成
	void GameAutoFillAny(CPoint point, int numk);// 游戏的自动填充	
};

