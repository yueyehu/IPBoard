
// IPBoardView.h : CIPBoardView ��Ľӿ�
//

#pragma once


class CIPBoardView : public CView
{
protected: // �������л�����
	CIPBoardView();
	DECLARE_DYNCREATE(CIPBoardView)

// ����
public:
	CIPBoardDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CIPBoardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // IPBoardView.cpp �еĵ��԰汾
inline CIPBoardDoc* CIPBoardView::GetDocument() const
   { return reinterpret_cast<CIPBoardDoc*>(m_pDocument); }
#endif

