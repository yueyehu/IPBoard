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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWndEx::OnLButtonDown(nFlags, point);
}


void CSplitterWndExt::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWndEx::OnLButtonUp(nFlags, point);
}


void CSplitterWndExt::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//CSplitterWndEx::OnMouseMove(nFlags, point);
}
