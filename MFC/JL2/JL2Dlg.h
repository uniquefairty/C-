// JL2Dlg.h : header file
//

#if !defined(AFX_JL2DLG_H__327B885A_8E2A_44CE_9DD4_73A16ECDFFC5__INCLUDED_)
#define AFX_JL2DLG_H__327B885A_8E2A_44CE_9DD4_73A16ECDFFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJL2Dlg dialog

class CJL2Dlg : public CDialog
{
// Construction
public:
	CJL2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJL2Dlg)
	enum { IDD = IDD_JL2_DIALOG };
	int		m_num1;
	int		m_num2;
	int		m_result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJL2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSub();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL2DLG_H__327B885A_8E2A_44CE_9DD4_73A16ECDFFC5__INCLUDED_)
