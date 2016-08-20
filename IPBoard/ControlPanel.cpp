// ControlPanel.cpp : 实现文件
//

#include "stdafx.h"
#include "Includes.h"
#include "ControlPanel.h"


// ControlPanel

IMPLEMENT_DYNCREATE(ControlPanel, CFormView)

ControlPanel::ControlPanel()
	: CFormView(ControlPanel::IDD)
{

}

ControlPanel::~ControlPanel()
{
}

void ControlPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEGREE, v_ComboDegree);
}

BEGIN_MESSAGE_MAP(ControlPanel, CFormView)
	ON_BN_CLICKED(IDC_BUTTONONE, &ControlPanel::OnBnClickedButtonone)
	ON_BN_CLICKED(IDC_BUTTONTWO, &ControlPanel::OnBnClickedButtontwo)
	ON_BN_CLICKED(IDC_BUTTONTHREE, &ControlPanel::OnBnClickedButtonthree)
	ON_BN_CLICKED(IDC_BUTTONFOUR, &ControlPanel::OnBnClickedButtonfour)
	ON_BN_CLICKED(IDC_RADIO_MANUAL, &ControlPanel::OnBnClickedRadioManual)
	ON_BN_CLICKED(IDC_RADIO_AUTO, &ControlPanel::OnBnClickedRadioAuto)
	ON_CBN_SELCHANGE(IDC_COMBO_DEGREE, &ControlPanel::OnCbnSelchangeComboDegree)
	ON_BN_CLICKED(IDC_BUTTON_NEWGAME, &ControlPanel::OnBnClickedButtonNewgame)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &ControlPanel::OnBnClickedButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_OVER, &ControlPanel::OnBnClickedButtonOver)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &ControlPanel::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, &ControlPanel::OnBnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_GOON, &ControlPanel::OnBnClickedButtonGoon)
	ON_COMMAND(ID_NEW_GAME, &ControlPanel::OnNewGame)
	ON_COMMAND(ID_OPEN, &ControlPanel::OnOpen)
	ON_COMMAND(ID_SAVE, &ControlPanel::OnSave)
	ON_COMMAND(ID_PAUSE, &ControlPanel::OnPause)
	ON_COMMAND(ID_GOON, &ControlPanel::OnGoon)
END_MESSAGE_MAP()


// ControlPanel 诊断

#ifdef _DEBUG
void ControlPanel::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void ControlPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// ControlPanel 消息处理程序


void ControlPanel::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	HBITMAP   hBitmap;   
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAPONE)); // IDB_BITMAP_TEST为资源图片ID  
	((CButton *)GetDlgItem(IDC_BUTTONONE))->SetBitmap(hBitmap);
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAPTWO)); // IDB_BITMAP_TEST为资源图片ID  
	((CButton *)GetDlgItem(IDC_BUTTONTWO))->SetBitmap(hBitmap);
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAPTHREE)); // IDB_BITMAP_TEST为资源图片ID  
	((CButton *)GetDlgItem(IDC_BUTTONTHREE))->SetBitmap(hBitmap);
	hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAPFOUR)); // IDB_BITMAP_TEST为资源图片ID  
	((CButton *)GetDlgItem(IDC_BUTTONFOUR))->SetBitmap(hBitmap);

	InitialNotify();
	InitialComboDegree();
	InitialRadio();
	SetTimer(TIMER1,10,NULL);
}


void ControlPanel::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	UpdateTime(pDoc->v_GameInfo.v_Time);
	if(pDoc->v_GameInfo.v_GameSaveSign != 0)
	{
		if(pDoc->v_GameInfo.v_GameSaveSign == 2) //判断棋盘是否更新过
		{
			pDoc->v_GameInfo.v_GameSaveSign = 0;
		}
		else
		{
			pDoc->v_GameInfo.v_GameSaveSign = 3;
		}

		if(pDoc->v_GameInfo.v_ManualOrAuto == false)
		{
			((CButton *)GetDlgItem(IDC_RADIO_MANUAL))->SetCheck(false);//选上
			((CButton *)GetDlgItem(IDC_RADIO_AUTO))->SetCheck(true);//不选
		}
		else
		{
			((CButton *)GetDlgItem(IDC_RADIO_MANUAL))->SetCheck(true);//选上
			((CButton *)GetDlgItem(IDC_RADIO_AUTO))->SetCheck(false);//不选
		}
		v_ComboDegree.SetCurSel(pDoc->v_GameInfo.v_BoardNumK-1);
	}
}


void ControlPanel::OnBnClickedButtonone()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_PieceType = 1;
}


void ControlPanel::OnBnClickedButtontwo()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_PieceType = 2;
}


void ControlPanel::OnBnClickedButtonthree()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_PieceType = 3;
}


void ControlPanel::OnBnClickedButtonfour()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_PieceType = 4;
}


// 初始化下拉列表
void ControlPanel::InitialComboDegree(void)
{
	v_ComboDegree.InsertString(0,"1");
	v_ComboDegree.InsertString(1,"2");
	v_ComboDegree.InsertString(2,"3");
	v_ComboDegree.InsertString(3,"4");
	v_ComboDegree.InsertString(4,"5");
	v_ComboDegree.InsertString(5,"6");
	v_ComboDegree.InsertString(6,"7");
	v_ComboDegree.SetCurSel(0);
}


// 初始化单选框
void ControlPanel::InitialRadio(void)
{
	((CButton *)GetDlgItem(IDC_RADIO_MANUAL))->SetCheck(true);//选上
	((CButton *)GetDlgItem(IDC_RADIO_AUTO))->SetCheck(false);//不选
}


// 初始化通知
void ControlPanel::InitialNotify(void)
{
	UpdateTime(0);
}


// 更新时间
void ControlPanel::UpdateTime(int time)
{
	CString str;
	str.Format("时间     %02d:%02d:%02d",time/6000,(time%6000)/100,time%100);
	GetDlgItem(IDC_STATIC_TIME)->SetWindowText(str);
}


void ControlPanel::OnBnClickedRadioManual()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_ManualOrAuto = true;
	pDoc->v_GameInfo.GameRestart();
	pDoc->UpdateAllViews(NULL,0,0);
}


void ControlPanel::OnBnClickedRadioAuto()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_ManualOrAuto = false;
	pDoc->v_GameInfo.GameAutoFill();
	pDoc->v_GameInfo.v_GameAutoFillCount = 0;
	pDoc->v_GameInfo.v_Time = 0;
	SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
}


void ControlPanel::OnCbnSelchangeComboDegree()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->v_GameInfo.v_BoardNumK != v_ComboDegree.GetCurSel()+1)
	{
		pDoc->v_GameInfo.v_BoardNumK = v_ComboDegree.GetCurSel()+1;
		pDoc->v_GameInfo.GameInit();
		pDoc->v_GameInfo.v_UpdateSign = true;
		if(pDoc->v_GameInfo.v_ManualOrAuto == false)
		{
			pDoc->v_GameInfo.GameAutoFill();
			SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
		}
		pDoc->UpdateAllViews(NULL,0,0);
	}
}


void ControlPanel::OnBnClickedButtonNewgame()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.GameInit();
	pDoc->v_GameInfo.v_UpdateSign = true;
	if(pDoc->v_GameInfo.v_ManualOrAuto == false)
	{
		pDoc->v_GameInfo.GameAutoFill();
		SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
	}

	pDoc->UpdateAllViews(NULL,0,0);
}


void ControlPanel::OnTimer(UINT_PTR nIDEvent)
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(pDoc->v_GameInfo.v_GameRunningSign == false) return;
	switch(nIDEvent)
	{
		case TIMER1:
		{
			pDoc->v_GameInfo.v_Time++;
			pDoc->v_GameInfo.v_UpdateSign = false;
		}
		break;
		case TIMER2:
		{
			if(pDoc->v_GameInfo.v_GameAutoFillCount < pDoc->v_GameInfo.v_ChessList.GetSize())
			{
				pDoc->v_GameInfo.v_GameAutoFillCount++;
				pDoc->v_GameInfo.v_GameAutoUpdateSign = true;
			}
		}
		break;
		default:
			break;
	}
	pDoc->UpdateAllViews(NULL,0,0);
	CFormView::OnTimer(nIDEvent);
}


void ControlPanel::OnDraw(CDC* /*pDC*/)
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	UpdateTime(pDoc->v_GameInfo.v_Time);
}


void ControlPanel::OnBnClickedButtonPause()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_GameRunningSign = false;
}


void ControlPanel::OnBnClickedButtonOver()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.GameOver();
	::SendMessage(AfxGetMainWnd()->m_hWnd,WM_CLOSE,0,0);
}


void ControlPanel::OnBnClickedButtonSave()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString FilePathName;
	CFileDialog dlg(false,
					NULL,
					NULL, 
					OFN_HIDEREADONLY |OFN_OVERWRITEPROMPT,
					(LPCTSTR)_TEXT("DAT Files (*.dat)|*.dat|All Files (*.*)|*.*||"),
					NULL);
	if(dlg.DoModal() == IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		CFile fi;
		if(fi.Open(FilePathName,CFile::modeCreate|CFile::modeWrite) == false )
		{
			fi.Close();
			return ;
		}
		CArchive ar(&fi,CArchive::store);
		pDoc->v_GameInfo.Serialize(ar);
		ar.Close();
		fi.Close();
	}
}


void ControlPanel::OnBnClickedButtonOpen()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString FilePathName;
	CFileDialog dlg(true,
					NULL,
					NULL, 
					OFN_HIDEREADONLY |OFN_OVERWRITEPROMPT,
					(LPCTSTR)_TEXT("DAT Files (*.dat)|*.dat|All Files (*.*)|*.*||"),
					NULL);
	if(dlg.DoModal() == IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		pDoc->v_GameInfo.v_GameSaveSign = 1;
		CFile fi;
		if(fi.Open(FilePathName,CFile::modeRead) == false)
		{
			fi.Close();
			return ;
		}
		CArchive ar(&fi,CArchive::load);
		pDoc->v_GameInfo.Serialize(ar);
		ar.Close();
		fi.Close();
		SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
		pDoc->UpdateAllViews(NULL,0,0);
	}
}


void ControlPanel::OnBnClickedButtonGoon()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_GameRunningSign = true;
}


void ControlPanel::OnNewGame()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.GameInit();
	pDoc->v_GameInfo.v_UpdateSign = true;
	if(pDoc->v_GameInfo.v_ManualOrAuto == false)
	{
		pDoc->v_GameInfo.GameAutoFill();
		SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
	}

	pDoc->UpdateAllViews(NULL,0,0);
}


void ControlPanel::OnOpen()
{	
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString FilePathName;
	CFileDialog dlg(true,
					NULL,
					NULL, 
					OFN_HIDEREADONLY |OFN_OVERWRITEPROMPT,
					(LPCTSTR)_TEXT("DAT Files (*.dat)|*.dat|All Files (*.*)|*.*||"),
					NULL);
	if(dlg.DoModal() == IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		pDoc->v_GameInfo.v_GameSaveSign = 1;
		CFile fi;
		if(fi.Open(FilePathName,CFile::modeRead) == false)
		{
			fi.Close();
			return ;
		}
		CArchive ar(&fi,CArchive::load);
		pDoc->v_GameInfo.Serialize(ar);
		ar.Close();
		fi.Close();
		SetTimer(TIMER2,pDoc->v_GameInfo.v_GameAutoFillTime,NULL);
		pDoc->UpdateAllViews(NULL,0,0);
	}
}


void ControlPanel::OnSave()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString FilePathName;
	CFileDialog dlg(false,
					NULL,
					NULL, 
					OFN_HIDEREADONLY |OFN_OVERWRITEPROMPT,
					(LPCTSTR)_TEXT("DAT Files (*.dat)|*.dat|All Files (*.*)|*.*||"),
					NULL);
	if(dlg.DoModal() == IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		CFile fi;
		if(fi.Open(FilePathName,CFile::modeCreate|CFile::modeWrite) == false )
		{
			fi.Close();
			return ;
		}
		CArchive ar(&fi,CArchive::store);
		pDoc->v_GameInfo.Serialize(ar);
		ar.Close();
		fi.Close();
	}
}


void ControlPanel::OnPause()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_GameRunningSign = false;
}


void ControlPanel::OnGoon()
{
	CIPBoardDoc* pDoc = (CIPBoardDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->v_GameInfo.v_GameRunningSign = true;
}
