// JL11.h : main header file for the JL11 application
//

#if !defined(AFX_JL11_H__BC64849F_0523_48B4_BF07_BCF1A52FE5B3__INCLUDED_)
#define AFX_JL11_H__BC64849F_0523_48B4_BF07_BCF1A52FE5B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL11App:
// See JL11.cpp for the implementation of this class
//

class CJL11App : public CWinApp
{
public:
	CJL11App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL11App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJL11App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL11_H__BC64849F_0523_48B4_BF07_BCF1A52FE5B3__INCLUDED_)
