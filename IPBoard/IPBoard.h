
// IPBoard.h : IPBoard Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CIPBoardApp:
// �йش����ʵ�֣������ IPBoard.cpp
//

class CIPBoardApp : public CWinApp
{
public:
	CIPBoardApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIPBoardApp theApp;
