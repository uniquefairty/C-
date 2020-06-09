// JL99.h : main header file for the JL99 application
//

#if !defined(AFX_JL99_H__6EE1C49F_3879_48F5_9A63_D114C1BA9102__INCLUDED_)
#define AFX_JL99_H__6EE1C49F_3879_48F5_9A63_D114C1BA9102__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL99App:
// See JL99.cpp for the implementation of this class
//

class CJL99App : public CWinApp
{
public:
	CJL99App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL99App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CJL99App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL99_H__6EE1C49F_3879_48F5_9A63_D114C1BA9102__INCLUDED_)
