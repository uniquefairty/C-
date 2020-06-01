// JL1.h : main header file for the JL1 application
//

#if !defined(AFX_JL1_H__9451B71B_313F_4FB9_8654_AA22A14AF12A__INCLUDED_)
#define AFX_JL1_H__9451B71B_313F_4FB9_8654_AA22A14AF12A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL1App:
// See JL1.cpp for the implementation of this class
//

class CJL1App : public CWinApp
{
public:
	CJL1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJL1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL1_H__9451B71B_313F_4FB9_8654_AA22A14AF12A__INCLUDED_)
