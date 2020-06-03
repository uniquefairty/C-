// JL9Dlg.h : header file
//

#if !defined(AFX_JL9DLG_H__478DF9B6_7EA6_4CBD_8728_DC67A63E7A9A__INCLUDED_)
#define AFX_JL9DLG_H__478DF9B6_7EA6_4CBD_8728_DC67A63E7A9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJL9Dlg dialog

class CJL9Dlg : public CDialog
{
// Construction
public:
	CJL9Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJL9Dlg)
	enum { IDD = IDD_JL9_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL9Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJL9Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL9DLG_H__478DF9B6_7EA6_4CBD_8728_DC67A63E7A9A__INCLUDED_)
