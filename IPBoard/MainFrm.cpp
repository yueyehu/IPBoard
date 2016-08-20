
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Includes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
END_MESSAGE_MAP()

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
	KillTimer(TIMER1);
    KillTimer(TIMER2);
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	cs.cx = 4*GetSystemMetrics(SM_CXFULLSCREEN)/5;
	cs.cy = 4*GetSystemMetrics(SM_CYFULLSCREEN)/5;
	cs.style &= ~WS_MAXIMIZEBOX;//禁止最大化
    cs.style &= ~WS_THICKFRAME;//禁止调整大小
	cs.lpszName="残缺棋盘"; 
	cs.style&=~FWS_ADDTOTITLE;

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CRect rect;
	GetWindowRect(&rect);
	m_wndSplitter.CreateStatic(this,1,2);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CIPBoardView),CSize(4*rect.Width()/5,0),pContext);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(ControlPanel),CSize(300,0),pContext);
	return TRUE;
}
