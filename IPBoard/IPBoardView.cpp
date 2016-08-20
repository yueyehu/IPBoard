
// IPBoardView.cpp : CIPBoardView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "IPBoard.h"
#endif

#include "Includes.h"
#include "IPBoardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIPBoardView

IMPLEMENT_DYNCREATE(CIPBoardView, CView)

BEGIN_MESSAGE_MAP(CIPBoardView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CIPBoardView 构造/析构

CIPBoardView::CIPBoardView()
{
	// TODO: 在此处添加构造代码

}

CIPBoardView::~CIPBoardView()
{
}

BOOL CIPBoardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CIPBoardView 绘制

void CIPBoardView::OnDraw(CDC* pDC)
{
	CIPBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.BoardDraw(pDC);
	pDoc->v_GameInfo.IPPieceDraw(pDC);
	if(pDoc->v_GameInfo.v_ManualOrAuto == false) 
	{
		ChessNode chessnode;
		for(int i = 0;i<pDoc->v_GameInfo.v_GameAutoFillCount;i++)
		//for(int i = 0;i<pDoc->v_GameInfo.v_ChessList.GetSize();i++)
		{
			chessnode = pDoc->v_GameInfo.v_ChessList.GetAt(i);
			pDoc->v_GameInfo.FillChessDraw(pDC,chessnode);
		}
	}
	else
	{
		ChessNode chessnode;
		for(int i = 0;i<pDoc->v_GameInfo.v_ChessList.GetSize();i++)
		{
			chessnode = pDoc->v_GameInfo.v_ChessList.GetAt(i);
			pDoc->v_GameInfo.FillChessDraw(pDC,chessnode);
		}
	}
}


// CIPBoardView 诊断

#ifdef _DEBUG
void CIPBoardView::AssertValid() const
{
	CView::AssertValid();
}

void CIPBoardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIPBoardDoc* CIPBoardView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIPBoardDoc)));
	return (CIPBoardDoc*)m_pDocument;
}
#endif //_DEBUG


// CIPBoardView 消息处理程序


void CIPBoardView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类
	CIPBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);
	pDoc->v_GameInfo.v_ViewSize.x	   = rect.right;
	pDoc->v_GameInfo.v_ViewSize.y	   = rect.bottom;
	pDoc->v_GameInfo.v_PixelsPerFootX  = pDC->GetDeviceCaps(LOGPIXELSX);//水平分辨率(pixel)
	pDoc->v_GameInfo.v_PixelsPerFootY  = pDC->GetDeviceCaps(LOGPIXELSY);//垂直分辨率(pixel) 
	pDoc->v_GameInfo.v_OriginalPoint.x = (rect.right-rect.left)/2 - pDoc->v_GameInfo.GetBoardSize()/2;
	pDoc->v_GameInfo.v_OriginalPoint.y = (rect.bottom-rect.top)/2 - pDoc->v_GameInfo.GetBoardSize()/2;
	pDC->SetViewportOrg(CPoint(pDoc->v_GameInfo.v_OriginalPoint.x,pDoc->v_GameInfo.v_OriginalPoint.y));  //设置视图原点
	//pDC->SetMapMode(MM_LOENGLISH); 

	CView::OnPrepareDC(pDC, pInfo);
}


void CIPBoardView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CIPBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(!pDoc->v_GameInfo.v_ManualOrAuto)  return ;
	if(!pDoc->v_GameInfo.CheckMouseDown(point)) return;
	CDC *pDC = GetDC();
	pDC->SetViewportOrg(CPoint(pDoc->v_GameInfo.v_OriginalPoint.x,pDoc->v_GameInfo.v_OriginalPoint.y));  
	//pDC->SetMapMode(MM_LOENGLISH);  
	
	if(pDoc->v_GameInfo.GetMouseBoardPos(point))
	{
		if(pDoc->v_GameInfo.CheckFillChess(ChessNode(pDoc->v_GameInfo.v_FillPiecePos,pDoc->v_GameInfo.v_PieceType)))
		{
			pDoc->v_GameInfo.AddChessInfo(ChessNode(pDoc->v_GameInfo.v_FillPiecePos,pDoc->v_GameInfo.v_PieceType));
			pDoc->v_GameInfo.FillChessDraw(pDC,ChessNode(pDoc->v_GameInfo.v_FillPiecePos,pDoc->v_GameInfo.v_PieceType));
			if(pDoc->v_GameInfo.CheckGameOver()) pDoc->v_GameInfo.GameOver();
		}
	}
	ReleaseDC(pDC);
	CView::OnLButtonDown(nFlags, point);
}


void CIPBoardView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	CIPBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC *pDC = GetDC();
	ASSERT_VALID(pDC);
	pDC->SetViewportOrg(CPoint(pDoc->v_GameInfo.v_OriginalPoint.x,pDoc->v_GameInfo.v_OriginalPoint.y));
	if(pDoc->v_GameInfo.v_UpdateSign == true )
	{
		Invalidate();
	}

	if(pDoc->v_GameInfo.v_GameSaveSign != 0)
	{
		if(pDoc->v_GameInfo.v_GameSaveSign == 3) //判断控制板是否更新过
		{
			pDoc->v_GameInfo.v_GameSaveSign = 0;
		}
		else
		{
			pDoc->v_GameInfo.v_GameSaveSign = 2;
		}
		Invalidate();
	}

	if(pDoc->v_GameInfo.v_GameAutoUpdateSign == true)
	{
		ChessNode chessnode;
		chessnode = pDoc->v_GameInfo.v_ChessList.GetAt(pDoc->v_GameInfo.v_GameAutoFillCount-1);
		pDoc->v_GameInfo.FillChessDraw(pDC,chessnode);
		pDoc->v_GameInfo.v_GameAutoUpdateSign = false;
		if(pDoc->v_GameInfo.v_GameAutoFillCount == pDoc->v_GameInfo.v_ChessList.GetSize())
		{
			pDoc->v_GameInfo.GameOver();
		}
	}
	ReleaseDC(pDC);
}
