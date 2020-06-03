// JL9.h : main header file for the JL9 application
//

#if !defined(AFX_JL9_H__7AE1DB69_6D35_4E65_AAEE_740A39771AC6__INCLUDED_)
#define AFX_JL9_H__7AE1DB69_6D35_4E65_AAEE_740A39771AC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL9App:
// See JL9.cpp for the implementation of this class
//

class CJL9App : public CWinApp
{
public:
	CJL9App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL9App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJL9App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL9_H__7AE1DB69_6D35_4E65_AAEE_740A39771AC6__INCLUDED_)
