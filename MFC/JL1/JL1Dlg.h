// JL1Dlg.h : header file
//

#if !defined(AFX_JL1DLG_H__281EB181_AEB3_45FF_A377_D970CF7717B7__INCLUDED_)
#define AFX_JL1DLG_H__281EB181_AEB3_45FF_A377_D970CF7717B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJL1Dlg dialog

class CJL1Dlg : public CDialog
{
// Construction
public:
	CJL1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJL1Dlg)
	enum { IDD = IDD_JL1_DIALOG };
	CString	m_strAnswer;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJL1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL1DLG_H__281EB181_AEB3_45FF_A377_D970CF7717B7__INCLUDED_)
