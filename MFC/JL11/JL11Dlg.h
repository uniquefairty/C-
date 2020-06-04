// JL11Dlg.h : header file
//
 
#if !defined(AFX_JL11DLG_H__648645A7_C822_42BE_B431_C7A2EFED2AA9__INCLUDED_)
#define AFX_JL11DLG_H__648645A7_C822_42BE_B431_C7A2EFED2AA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJL11Dlg dialog

class CJL11Dlg : public CDialog
{
// Construction
public:
	CJL11Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJL11Dlg)
	enum { IDD = IDD_JL11_DIALOG };
	CString	m_stredit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL11Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	COLORREF m_colorref;
	CToolBar m_wndToolBar;

	// Generated message map functions
	//{{AFX_MSG(CJL11Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void OnFileExit();
	afx_msg void OnMessEllipse();
	afx_msg void OnMessText();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnQuickBlue();
	afx_msg void OnQuickHide();
	afx_msg void OnQuickRed();
	afx_msg void OnQuickShow();
	afx_msg void OnQuickWhite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL11DLG_H__648645A7_C822_42BE_B431_C7A2EFED2AA9__INCLUDED_)
