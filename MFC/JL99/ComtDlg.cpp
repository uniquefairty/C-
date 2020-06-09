// ComtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "JL99.h"
#include "ComtDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComtDlg dialog


CComtDlg::CComtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComtDlg)
	m_nLine = 0;
	m_nRadius = 0;
	//}}AFX_DATA_INIT
}


void CComtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComtDlg)
	DDX_Control(pDX, IDC_SLIDERRADIUS, m_Slider);
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDX_Text(pDX, IDC_EDIT1, m_nLine);
	DDX_Slider(pDX, IDC_SLIDERRADIUS, m_nRadius);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComtDlg, CDialog)
	//{{AFX_MSG_MAP(CComtDlg)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComtDlg message handlers

BOOL CComtDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Spin.SetRange(1,10);
	m_Spin.SetPos(1);
	m_Slider.SetRange(1,200);
	m_Slider.SetTicFreq(10);
	m_Slider.SetPos(50);
	m_Slider.SetSelection(50,150);
	SetDlgItemText(IDC_STATICRADIUS,"°ë¾¶£º50");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CComtDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	if(pScrollBar->GetDlgCtrlID()==IDC_SLIDERRADIUS)
	    m_nRadius=m_Slider.GetPos();
      CString strRadius;
      strRadius.Format("°ë¾¶:%d",m_nRadius);
      SetDlgItemText(IDC_STATICRADIUS,strRadius);

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
