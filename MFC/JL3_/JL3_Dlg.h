// JL3_Dlg.h : header file
//

#if !defined(AFX_JL3_DLG_H__1B414778_65A1_40B9_AA6C_167D384AED2A__INCLUDED_)
#define AFX_JL3_DLG_H__1B414778_65A1_40B9_AA6C_167D384AED2A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJL3_Dlg dialog

class CJL3_Dlg : public CDialog
{
// Construction
public:
	CJL3_Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJL3_Dlg)
	enum { IDD = IDD_JL3__DIALOG };
	double	m_num1;
	double	m_num2;
	double	m_num3;
	double	m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL3_Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJL3_Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFun();
	afx_msg void OnNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL3_DLG_H__1B414778_65A1_40B9_AA6C_167D384AED2A__INCLUDED_)
