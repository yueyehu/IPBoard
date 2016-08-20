#pragma once
#include "afxwin.h"



// ControlPanel ������ͼ

class ControlPanel : public CFormView
{
	DECLARE_DYNCREATE(ControlPanel)

protected:
	ControlPanel();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnBnClickedButtonone();
	afx_msg void OnBnClickedButtontwo();
	afx_msg void OnBnClickedButtonthree();
	afx_msg void OnBnClickedButtonfour();
	// ��ʼ�������б�
	void InitialComboDegree(void);
	CComboBox v_ComboDegree;
	// ��ʼ����ѡ��
	void InitialRadio(void);
	// ��ʼ��֪ͨ
	void InitialNotify(void);
	// ����ʱ��
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


