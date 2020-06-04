// JL11Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "JL11.h"
#include "JL11Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL11Dlg dialog

CJL11Dlg::CJL11Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJL11Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJL11Dlg)
	m_stredit = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJL11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJL11Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_stredit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJL11Dlg, CDialog)
	//{{AFX_MSG_MAP(CJL11Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_MESS_ELLIPSE, OnMessEllipse)
	ON_COMMAND(ID_MESS_TEXT, OnMessText)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_QUICK_BLUE, OnQuickBlue)
	ON_COMMAND(ID_QUICK_HIDE, OnQuickHide)
	ON_COMMAND(ID_QUICK_RED, OnQuickRed)
	ON_COMMAND(ID_QUICK_SHOW, OnQuickShow)
	ON_COMMAND(ID_QUICK_WHITE, OnQuickWhite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL11Dlg message handlers

BOOL CJL11Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	if(!m_wndToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_ALIGN_TOP)
      ||!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
	    return -1;
	} 
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CJL11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CJL11Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;//矩形类
		CPaintDC dc(this);
		GetClientRect(rect);//获取客户区矩形区域
		dc.FillSolidRect(rect,m_colorref);//用指定颜色填充给定矩形区域

		CDialog::OnPaint();

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CJL11Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJL11Dlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CJL11Dlg::OnFileExit() 
{
	// TODO: Add your command handler code here
	int answer=MessageBox("你正在关闭应用程序","确定退出",MB_ICONQUESTION|MB_OKCANCEL);
	if(answer==IDOK)
	{
		CDialog::OnOK();
	}
	
}

void CJL11Dlg::OnMessEllipse() 
{
	// TODO: Add your command handler code here
	CClientDC dc(this);//画布
	dc.Ellipse(100,100,300,150);//画椭圆
	
}

void CJL11Dlg::OnMessText() 
{
	// TODO: Add your command handler code here
	m_stredit="你好，世界";
	UpdateData(FALSE);
	
}

void CJL11Dlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu(IDR_QUICKMENU);
	CMenu* pquickmenu=menu.GetSubMenu(0);
	pquickmenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,pWnd);
	
}

void CJL11Dlg::OnQuickBlue() 
{
	// TODO: Add your command handler code here
	m_colorref=RGB(0,0,255);
	Invalidate();//系统调用Onpaint函数

}

void CJL11Dlg::OnQuickHide() 
{
	// TODO: Add your command handler code here
	Invalidate();//系统调用Onpaint函数
}

void CJL11Dlg::OnQuickRed() 
{
	// TODO: Add your command handler code here
	m_colorref=RGB(255,0,0);
	Invalidate();//系统调用Onpaint函数
	
}

void CJL11Dlg::OnQuickShow() 
{
	// TODO: Add your command handler code here
	OnMessText();
	
}

void CJL11Dlg::OnQuickWhite() 
{
	// TODO: Add your command handler code here
	m_colorref=RGB(255,255,255);
	Invalidate();//系统调用Onpaint函数
	
}
