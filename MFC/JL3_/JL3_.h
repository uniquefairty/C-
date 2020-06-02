// JL3_.h : main header file for the JL3_ application
//

#if !defined(AFX_JL3__H__231F1895_9E07_4DAD_AE88_77AFB395B258__INCLUDED_)
#define AFX_JL3__H__231F1895_9E07_4DAD_AE88_77AFB395B258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJL3_App:
// See JL3_.cpp for the implementation of this class
//

class CJL3_App : public CWinApp
{
public:
	CJL3_App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL3_App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJL3_App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL3__H__231F1895_9E07_4DAD_AE88_77AFB395B258__INCLUDED_)
