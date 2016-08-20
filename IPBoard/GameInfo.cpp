#include "StdAfx.h"
#include "Includes.h"
#include "GameInfo.h"

IMPLEMENT_SERIAL(GameInfo,CObject,1);//1�ǰ汾�ţ��������ָ��һ��ֵ
GameInfo::GameInfo(void)
	: v_ViewSize(0)
	, v_PixelsPerFootX(0)
	, v_PixelsPerFootY(0)
	, v_ChessPieceSize(0)
	, v_BoardNumK(0)
	, v_IPPiecePos(0)
	, v_OriginalPoint(0)
	, v_FillPiecePos(0)
	, vp_PieceSign(NULL)
	, v_PieceType(0)
	, v_BoardPieceNum(0)
	, v_ManualOrAuto(false)
	, v_GameRunningSign(false)
	, v_Time(0)
	, v_UpdateSign(false)
	, v_GameAutoFillCount(0)
	, v_GameAutoUpdateSign(false)
	, v_GameAutoFillTime(0)
	, v_GameSaveSign(0)
{
	v_BoardNumK = 1;
	v_GameAutoFillTime = 400;
	v_ManualOrAuto = true;
	v_GameSaveSign = 0;
	GameInit();
}


GameInfo::~GameInfo(void)
{
}


// ��ȡ������ÿ�е�������
int GameInfo::GetBoardPieceNum(void)
{
	int temp = 1;
	for(int i = 0;i< v_BoardNumK;i++)
	{
		temp = 2*temp;
	}
	v_BoardPieceNum = temp;
	return temp;
}


// ��ȡ���̵ĳߴ�
int GameInfo::GetBoardSize(void)
{
	int temp = 1;
	for(int i = 0;i< v_BoardNumK;i++)
	{
		temp = 2*temp;
	}
	temp = temp*v_ChessPieceSize; 
	return temp;
}


// ��������
void GameInfo::BoardDraw(CDC * pDC)
{
	int t_boardsize = GetBoardPieceNum();
	CPen *p=new CPen();
    p->CreatePen(PS_SOLID,1, RGB(0,0,0));
    pDC->SelectObject(p);	
	for(int i = 0;i<=t_boardsize;i++)
	{
		pDC->MoveTo(i*v_ChessPieceSize,0);
		pDC->LineTo(i*v_ChessPieceSize,t_boardsize*v_ChessPieceSize);
	}
	for(int i = 0;i<=t_boardsize;i++)
	{
		pDC->MoveTo(0,i*v_ChessPieceSize);
		pDC->LineTo(t_boardsize*v_ChessPieceSize,i*v_ChessPieceSize);
	}
	p->DeleteObject();
}


// ��ȱ����λ�ó�ʼ��
void GameInfo::IPPieceInitial(void)
{
	int RandX;
	while(!(RandX= rand()%(GetBoardPieceNum()+1)));
	int RandY;
	while(!(RandY= rand()%(GetBoardPieceNum()+1)));
	v_IPPiecePos = CPoint(RandX,RandY);
	vp_PieceSign[(v_IPPiecePos.y-1)*v_BoardPieceNum + v_IPPiecePos.x-1] = 1;
}


// ��ȱ���ӵĻ���
void GameInfo::IPPieceDraw(CDC *pDC)
{
	CBrush *brush = new CBrush();
	brush->CreateSolidBrush(RGB(0,0,0));
	pDC->SelectObject(brush);
	pDC->Rectangle(v_IPPiecePos.x*v_ChessPieceSize,v_IPPiecePos.y*v_ChessPieceSize,(v_IPPiecePos.x-1)*v_ChessPieceSize,(v_IPPiecePos.y-1)*v_ChessPieceSize);
	brush->DeleteObject();
}


// ����һ����ȱʡ����
void GameInfo::FillChessOneDraw(CDC * pDC,CPoint pos)
{
	pos.y--;
	CBrush *brush = new CBrush();
	brush->CreateSolidBrush(RGB(255,0,0));
	pDC->SelectObject(brush);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	brush->DeleteObject();
}


// ���ڶ�����ȱʡ����
void GameInfo::FillChessTwoDraw(CDC * pDC,CPoint pos)
{
	pos.x--;pos.y--;
	CBrush *brush = new CBrush();
	brush->CreateSolidBrush(RGB(0,255,0));
	pDC->SelectObject(brush);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	brush->DeleteObject();
}


// ���������޵�ȱʡ����
void GameInfo::FillChessThreeDraw(CDC * pDC,CPoint pos)
{
	pos.x--;
	CBrush *brush = new CBrush();
	brush->CreateSolidBrush(RGB(0,0,255));
	pDC->SelectObject(brush);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	brush->DeleteObject();
}


// ���������޵�ȱʡ����
void GameInfo::FillChessFourDraw(CDC * pDC,CPoint pos)
{
	CBrush *brush = new CBrush();
	brush->CreateSolidBrush(RGB(255,255,0));
	pDC->SelectObject(brush);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x-1)*v_ChessPieceSize,(pos.y+1)*v_ChessPieceSize);
	pDC->Rectangle(pos.x*v_ChessPieceSize,pos.y*v_ChessPieceSize,(pos.x+1)*v_ChessPieceSize,(pos.y-1)*v_ChessPieceSize);
	
	brush->DeleteObject();
}

// �������ͼ
void GameInfo::FillChessDraw(CDC * pDC, ChessNode chessnode)
{
	switch(chessnode.v_ChessType)
	{
	case 1:
		FillChessOneDraw(pDC,chessnode.v_ChessPos);break;
	case 2:
		FillChessTwoDraw(pDC,chessnode.v_ChessPos);break;
	case 3:
		FillChessThreeDraw(pDC,chessnode.v_ChessPos);break;
	case 4:
		FillChessFourDraw(pDC,chessnode.v_ChessPos);break;
	default:
		break;
	}
}



// ������ת��Ϊ�ߴ�
CPoint GameInfo::ExchangeMousePixelToFoot(CPoint point)
{
	int tempx = point.x - v_OriginalPoint.x;
	int tempy = point.y - v_OriginalPoint.y;
	return CPoint(tempx,tempy);
}



// ��ȡ����������е�λ��
bool GameInfo::GetMouseBoardPos(CPoint point)
{
	point = ExchangeMousePixelToFoot(point);
	int tempx = point.x;
	int tempy = point.y;
	tempx = tempx/v_ChessPieceSize;
	tempy = tempy/v_ChessPieceSize;
	v_FillPiecePos.x = tempx + 1;
	v_FillPiecePos.y = tempy + 1;
	switch(v_PieceType)
	{
	case 1:
		if(v_FillPiecePos.x == GetBoardPieceNum() || v_FillPiecePos.y == 1) return false;break;
	case 2:
		if(v_FillPiecePos.x == 1 || v_FillPiecePos.y == 1) return false;break;
	case 3:
		if(v_FillPiecePos.x == 1 || v_FillPiecePos.y == GetBoardPieceNum()) return false;break;
	case 4:
		if(v_FillPiecePos.x == GetBoardPieceNum() || v_FillPiecePos.y == GetBoardPieceNum()) return false;break;
	default:
		break;
	}
	return true;
}


// �ж�������Ƿ���Ч
bool GameInfo::CheckMouseDown(CPoint point)
{
	int tempx = point.x - v_OriginalPoint.x;
	int tempy = point.y - v_OriginalPoint.y;
	if(tempx > 0 && tempy > 0 && tempx < GetBoardSize() && tempy < GetBoardSize()) return true;
	else return false;
}


// ��̬��������
void GameInfo::CreateSignArray(void)
{
	if(vp_PieceSign) delete []vp_PieceSign;
	switch(v_BoardNumK)
	{
	case 1:
		vp_PieceSign = new int[2*2];break;
	case 2:
		vp_PieceSign = new int[4*4];break;
	case 3:
		vp_PieceSign = new int[8*8];break;
	case 4:
		vp_PieceSign = new int[16*16];break;
	case 5:
		vp_PieceSign = new int[32*32];break;
	case 6:
		vp_PieceSign = new int[64*64];break;
	case 7:
		vp_PieceSign = new int[128*128];break;
	default:
		vp_PieceSign = new int[256*256];break;
	}
	for(int i =0 ;i<GetBoardPieceNum()*GetBoardPieceNum();i++)
	{
		vp_PieceSign[i] = 0;
	}
}


// �������̿�ߴ�
int GameInfo::SetChessPieceSize(int metric)
{
	if(v_PixelsPerFootX == 0) v_PixelsPerFootX = 96;
	v_ChessPieceSize = metric*v_PixelsPerFootX/254;
	return v_ChessPieceSize;
}


// ����������Ϣ
void GameInfo::AddChessInfo(ChessNode chessnode)
{
	CPoint pos = chessnode.v_ChessPos;
	switch(chessnode.v_ChessType)
	{
	case 1:
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-2)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x] = 1;
		break;
	case 2:
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-2)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-2] = 1;
		break;
	case 3:
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-2] = 1;
		break;
	case 4:
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y)*v_BoardPieceNum + pos.x-1] = 1;
		vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x] = 1;
		break;
	default:
		break;		
	}
	v_ChessList.Add(chessnode);
}


// �жϽ�Ҫ�����Ƿ��ͻ
bool GameInfo::CheckFillChess(ChessNode chessnode)
{
	CPoint pos = chessnode.v_ChessPos;
	switch(chessnode.v_ChessType)
	{
	case 1:
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] == 1)  return false;
		if(vp_PieceSign[(pos.y-2)*v_BoardPieceNum + pos.x-1] == 1)  return false;
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x] == 1)return false;
		break;
	case 2:
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y-2)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-2] == 1)return false;
		break;
	case 3:
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-2] == 1)return false;
		break;
	case 4:
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y)*v_BoardPieceNum + pos.x-1] == 1)return false;
		if(vp_PieceSign[(pos.y-1)*v_BoardPieceNum + pos.x] == 1)return false;
		break;
	default:
		break;		
	}
	return true;
}


// ��Ϸ��ʼ��
void GameInfo::GameInit(void)
{
	v_ChessList.RemoveAll();
	v_PieceType = 1;
	CreateSignArray();
	switch(v_BoardNumK)
	{
	case 1:
		SetChessPieceSize(200);break;
	case 2:
		SetChessPieceSize(150);break;
	case 3:
		SetChessPieceSize(100);break;
	case 4:
		SetChessPieceSize(90);break;
	case 5:
		SetChessPieceSize(45);break;
	case 6:
		SetChessPieceSize(20);break;
	case 7:
		SetChessPieceSize(13);break;
	default:
		SetChessPieceSize(90);break;
	}
	v_GameAutoFillCount = 0;
	v_GameAutoUpdateSign = false;
	IPPieceInitial();
	GetBoardPieceNum();
	v_Time = 0;
	v_GameRunningSign = true;
}


// ��Ϸ��������
void GameInfo::GameOver(void)
{
	//v_ChessList.RemoveAll();
	v_GameRunningSign = false;
}


// �ж���Ϸ�Ƿ����
bool GameInfo::CheckGameOver(void)
{
	if(v_ChessList.GetSize()*3 == v_BoardPieceNum*v_BoardPieceNum -1) return true;
	else return false;
}

// ��Ϸ�Զ����
void GameInfo::GameAutoFill()
{
	GameAutoFillAny(v_IPPiecePos,v_BoardNumK);
}


// ���һ�μ������
void GameInfo::GameAutoFillOne(CPoint point)
{
	if(point.x%2 == 0 && point.y%2 == 1)
	{
		AddChessInfo(ChessNode(CPoint(point.x-1,point.y+1),1));
	}
	else if(point.x%2 == 1 && point.y%2 == 1)
	{
		AddChessInfo(ChessNode(CPoint(point.x+1,point.y+1),2));
	}
	else if(point.x%2 == 1 && point.y%2 == 0)
	{
		AddChessInfo(ChessNode(CPoint(point.x+1,point.y-1),3));
	}
	else
	{
		AddChessInfo(ChessNode(CPoint(point.x-1,point.y-1),4));
	}

}

/*
// ������״�
void GameInfo::GameAutoFillTwo(CDC * pDC, CPoint point)
{
	//����4*4����ԭ������
	int tempx = ((point.x-1)/4)*4+1;
	int tempy = ((point.y-1)/4)*4+1;
	if((point.x-1)%4 > 1 && (point.y-1)%4 <= 1)
	{
		GameAutoFillOne(pDC,point);
		v_ChessList.Add(ChessNode(CPoint(tempx+1,tempy+2),1));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+1));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+2));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+2));

	}
	else if((point.x-1)%4 <=1 && (point.y-1)%4 <= 1)
	{
		GameAutoFillOne(pDC,point);
		v_ChessList.Add(ChessNode(CPoint(tempx+2,tempy+2),2));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+2));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+1));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+2));
	}
	else if((point.x-1)%4 <= 1 && (point.y-1)%4 >1)
	{
		GameAutoFillOne(pDC,point);
		v_ChessList.Add(ChessNode(CPoint(tempx+2,tempy+1),3));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+1));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+1));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+2));
	}
	else
	{
		GameAutoFillOne(pDC,point);
		v_ChessList.Add(ChessNode(CPoint(tempx+1,tempy+1),4));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+1));
		GameAutoFillOne(pDC,CPoint(tempx+1,tempy+2));
		GameAutoFillOne(pDC,CPoint(tempx+2,tempy+1));
	}
}
*/

// ��Ϸ���Զ����
void GameInfo::GameAutoFillAny(CPoint point, int numk) //����һ���ݹ����
{
	if(numk == 1)
	{
		GameAutoFillOne(point);
	}
	else
	{
		int fk = 1;
		for(int i = 0;i<numk;i++)
		{
			fk = fk * 2;
		}
		int tempx = ((point.x-1)/fk)*fk+1;//���ڼ���ݹ���õķ���ԭ��
		int tempy = ((point.y-1)/fk)*fk+1;
		if((point.x-1)%fk > fk/2-1 && (point.y-1)%fk <= fk/2-1)
		{
			GameAutoFillAny(point,numk-1);
			AddChessInfo(ChessNode(CPoint(tempx+fk/2-1,tempy+fk/2),1));
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2-1),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2),numk-1);

		}
		else if((point.x-1)%fk <= fk/2-1 && (point.y-1)%fk <= fk/2-1)
		{
			GameAutoFillAny(point,numk-1);
			AddChessInfo(ChessNode(CPoint(tempx+fk/2,tempy+fk/2),2));
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2-1),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2),numk-1);
		}
		else if((point.x-1)%fk <= fk/2-1 && (point.y-1)%fk > fk/2-1)
		{
			GameAutoFillAny(point,numk-1);
			AddChessInfo(ChessNode(CPoint(tempx+fk/2,tempy+fk/2-1),3));
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2-1),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2-1),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2),numk-1);
		}
		else
		{
			GameAutoFillAny(point,numk-1);
			AddChessInfo(ChessNode(CPoint(tempx+fk/2-1,tempy+fk/2-1),4));
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2-1),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2-1,tempy+fk/2),numk-1);
			GameAutoFillAny(CPoint(tempx+fk/2,tempy+fk/2-1),numk-1);
		}
	}
}

void GameInfo::Serialize(CArchive &ar)
{
	ChessNode chessnode;
	if(ar.IsStoring())
	{
		ar.WriteCount(v_ChessList.GetSize());
		ar<<v_IPPiecePos;         //�п�λ��
		ar<<v_BoardNumK;          //Kֵ
		ar<<v_ChessPieceSize;     //���ӳߴ�
		ar<<v_BoardPieceNum;      //ÿ�����Ӹ���
		ar<<v_ManualOrAuto;       //�Զ����ֶ���� true���ֶ� ��false���Զ�
		ar<<v_GameAutoFillCount;  //�Զ�������
		ar<<v_GameAutoFillTime;   //��Ϸ�Զ����ʱ����
		ar<<v_GameAutoUpdateSign; //��Ϸ�Զ����±�־
		ar<<v_GameRunningSign;    //��Ϸ���б�־
		ar<<v_PieceType;          //��Ϸ��������
		ar<<v_UpdateSign;         //���±�־
		ar<<v_Time;               //��Ϸ������ʱ��
		for(int i = 0;i<v_ChessList.GetSize();i++)
		{
			chessnode = v_ChessList.GetAt(i);
			ar<<chessnode.v_ChessType;
			ar<<chessnode.v_ChessPos;
		}
	}
	else
	{
		int t_Count = ar.ReadCount();
		v_ChessList.RemoveAll();
		ar>>v_IPPiecePos;
		ar>>v_BoardNumK;
		ar>>v_ChessPieceSize;
		ar>>v_BoardPieceNum;
		ar>>v_ManualOrAuto;
		ar>>v_GameAutoFillCount;
		ar>>v_GameAutoFillTime;
		ar>>v_GameAutoUpdateSign;
		ar>>v_GameRunningSign;
		ar>>v_PieceType;
		ar>>v_UpdateSign;
		ar>>v_Time;
		CreateSignArray();    //������־����
		for(int i = 0;i<t_Count;i++)
		{
			ar>>chessnode.v_ChessType;
			ar>>chessnode.v_ChessPos;
			AddChessInfo(chessnode);
		}
	}
}

// ��Ϸ���¿�ʼ
void GameInfo::GameRestart(void)
{
	v_ChessList.RemoveAll();
	CreateSignArray();
	v_UpdateSign = true;
	v_Time = 0;
	v_GameRunningSign = true;
}
