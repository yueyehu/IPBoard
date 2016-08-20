
// IPBoardView.h : CIPBoardView 类的接口
//

#pragma once


class CIPBoardView : public CView
{
protected: // 仅从序列化创建
	CIPBoardView();
	DECLARE_DYNCREATE(CIPBoardView)

// 特性
public:
	CIPBoardDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CIPBoardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // IPBoardView.cpp 中的调试版本
inline CIPBoardDoc* CIPBoardView::GetDocument() const
   { return reinterpret_cast<CIPBoardDoc*>(m_pDocument); }
#endif

