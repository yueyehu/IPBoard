#include "StdAfx.h"
#include "Includes.h"
#include "SplitterWndExt.h"


CSplitterWndExt::CSplitterWndExt(void)
{
}


CSplitterWndExt::~CSplitterWndExt(void)
{
}
BEGIN_MESSAGE_MAP(CSplitterWndExt, CSplitterWndEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CSplitterWndExt::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CSplitterWndEx::OnLButtonDown(nFlags, point);
}


void CSplitterWndExt::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CSplitterWndEx::OnLButtonUp(nFlags, point);
}


void CSplitterWndExt::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CSplitterWndEx::OnMouseMove(nFlags, point);
}
