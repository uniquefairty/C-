// JL14.h : main header file for the JL14 application
//

#if !defined(AFX_JL14_H__09507A55_7F15_4D31_8EDB_A11AE3B37E8B__INCLUDED_)
#define AFX_JL14_H__09507A55_7F15_4D31_8EDB_A11AE3B37E8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL14App:
// See JL14.cpp for the implementation of this class
//

class CJL14App : public CWinApp
{
public:
	CJL14App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL14App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJL14App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL14_H__09507A55_7F15_4D31_8EDB_A11AE3B37E8B__INCLUDED_)
