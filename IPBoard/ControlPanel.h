#pragma once
#include "afxwin.h"



// ControlPanel 窗体视图

class ControlPanel : public CFormView
{
	DECLARE_DYNCREATE(ControlPanel)

protected:
	ControlPanel();           // 动态创建所使用的受保护的构造函数
	virtual ~ControlPanel();

public:
	enum { IDD = IDD_CONTROLPANEL };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnBnClickedButtonone();
	afx_msg void OnBnClickedButtontwo();
	afx_msg void OnBnClickedButtonthree();
	afx_msg void OnBnClickedButtonfour();
	// 初始化下拉列表
	void InitialComboDegree(void);
	CComboBox v_ComboDegree;
	// 初始化单选框
	void InitialRadio(void);
	// 初始化通知
	void InitialNotify(void);
	// 更新时间
	void UpdateTime(int time);
	afx_msg void OnBnClickedRadioManual();
	afx_msg void OnBnClickedRadioAuto();
	afx_msg void OnCbnSelchangeComboDegree();
	afx_msg void OnBnClickedButtonNewgame();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnDraw(CDC* /*pDC*/);
	afx_msg void OnBnClickedButtonPause();
	afx_msg void OnBnClickedButtonOver();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonGoon();
	afx_msg void OnNewGame();
	afx_msg void OnOpen();
	afx_msg void OnSave();
	afx_msg void OnPause();
	afx_msg void OnGoon();
};


