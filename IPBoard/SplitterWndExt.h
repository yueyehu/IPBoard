#pragma once
#include "afxsplitterwndex.h"
class CSplitterWndExt :
	public CSplitterWndEx
{
public:
	CSplitterWndExt(void);
	~CSplitterWndExt(void);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

