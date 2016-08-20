#pragma once
#include "atltypes.h"
#include "ChessNode.h"
#include "afxtempl.h"
class GameInfo:public CObject
{
	DECLARE_SERIAL(GameInfo);// Ϊ���������л�

public:
	GameInfo(void);
	~GameInfo(void);

public:
	virtual void Serialize(CArchive &ar); //�������л�����

public:
	CPoint v_ViewSize;      // �ͻ�����ͼ��С
	int v_PixelsPerFootX;   // ��Ļ����ÿӢ��
	int v_PixelsPerFootY;   // ��Ļ����ÿӢ��
	
	int v_BoardNumK;        // �㷨�е�kֵ
	int v_ChessPieceSize;   // ���ӵĳߴ�,��Kֵ����
	int v_BoardPieceNum;    // ÿ�����ӵ���Ŀ
	CPoint v_OriginalPoint; // �������ʼλ�ã���Kֵ�Ϳͻ�����ͼ��С����
	
	CPoint v_IPPiecePos;    // ��ȱ���ӵ�λ��
	int v_GameAutoFillTime; //��Ϸ�Զ����ʱ����

	CPoint v_FillPiecePos;  // ��ʱ�洢��������
	CArray<ChessNode,ChessNode> v_ChessList;// ���ڴ洢������Ϣ
	int *vp_PieceSign;      // ���ڴ洢�����е������Ƿ�������Ϣ

	int v_PieceType;           // ���õ��������ͣ������ֶ�
	bool v_ManualOrAuto;       // ��ʶ�ֶ������Զ�
	bool v_GameAutoUpdateSign; // ��Ϸ�Զ�����
	bool v_UpdateSign;         // ���±�־
	int v_GameSaveSign;        // ��Ϸ�����־
	bool v_GameRunningSign;    // ��Ϸ���б�־

	int v_GameAutoFillCount;   // ��Ϸ�Զ����Ĵ���
	int v_Time;                // ��Ϸʱ��

public:
	void GameInit(void);     // ��Ϸ��ʼ��
	void GameOver(void);     // ��Ϸ��������
	bool CheckGameOver(void);// �ж���Ϸ�Ƿ����
	void GameRestart(void);  // ��Ϸ���¿�ʼ

	int GetBoardPieceNum(void);// ��ȡ������ÿ�е�������
	int GetBoardSize(void);    // ��ȡ���̵ĳߴ�

	void CreateSignArray(void);       // ��̬��������
	int SetChessPieceSize(int metric);// �������̿�ߴ�
	void IPPieceInitial(void);        // ��ȱ����λ�ó�ʼ��
	
	void BoardDraw(CDC * pDC); // ��������
	void IPPieceDraw(CDC *pDC);// ��ȱ���ӵĻ���

	void FillChessDraw(CDC * pDC, ChessNode chessnode);// �������ͼ
	void FillChessOneDraw(CDC * pDC,CPoint pos);       // ����һ����ȱʡ����
	void FillChessTwoDraw(CDC * pDC,CPoint pos);       // ���ڶ�����ȱʡ����
	void FillChessThreeDraw(CDC * pDC,CPoint pos);     // ���������޵�ȱʡ����
	void FillChessFourDraw(CDC * pDC,CPoint pos);      // ���������޵�ȱʡ����

	CPoint ExchangeMousePixelToFoot(CPoint point);// ������ת��Ϊ�ߴ�
	bool GetMouseBoardPos(CPoint point);          // ��ȡ����������е�λ��
	bool CheckMouseDown(CPoint point);            // �ж�������Ƿ���Ч
	bool CheckFillChess(ChessNode chessnode);     // �жϽ�Ҫ�����Ƿ��ͻ
	
	void AddChessInfo(ChessNode chessnode);// ����������Ϣ
	
	void GameAutoFill();               // ��Ϸ�Զ����
	void GameAutoFillOne(CPoint point);// ���һ�μ������
	void GameAutoFillAny(CPoint point, int numk);// ��Ϸ���Զ����	
};

