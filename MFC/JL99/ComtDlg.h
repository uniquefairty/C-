#if !defined(AFX_COMTDLG_H__02B1BDFB_366D_43DC_B35B_41CF435AF14D__INCLUDED_)
#define AFX_COMTDLG_H__02B1BDFB_366D_43DC_B35B_41CF435AF14D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComtDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CComtDlg dialog

class CComtDlg : public CDialog
{
// Construction
public:
	CComtDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComtDlg)
	enum { IDD = IDD_DIALOG1 };
	CSliderCtrl	m_Slider;
	CSpinButtonCtrl	m_Spin;
	UINT	m_nLine;
	int		m_nRadius;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComtDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMTDLG_H__02B1BDFB_366D_43DC_B35B_41CF435AF14D__INCLUDED_)
