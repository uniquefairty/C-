// JL2.h : main header file for the JL2 application
//

#if !defined(AFX_JL2_H__37379C04_C098_48F7_94BD_980D04D3314E__INCLUDED_)
#define AFX_JL2_H__37379C04_C098_48F7_94BD_980D04D3314E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL2App:
// See JL2.cpp for the implementation of this class
//

class CJL2App : public CWinApp
{
public:
	CJL2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJL2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL2_H__37379C04_C098_48F7_94BD_980D04D3314E__INCLUDED_)
