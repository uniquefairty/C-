// JL99Doc.cpp : implementation of the CJL99Doc class
//

#include "stdafx.h"
#include "JL99.h"

#include "JL99Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJL99Doc

IMPLEMENT_DYNCREATE(CJL99Doc, CDocument)

BEGIN_MESSAGE_MAP(CJL99Doc, CDocument)
	//{{AFX_MSG_MAP(CJL99Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL99Doc construction/destruction

CJL99Doc::CJL99Doc()
{
	// TODO: add one-time construction code here

}

CJL99Doc::~CJL99Doc()
{
}

BOOL CJL99Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJL99Doc serialization

void CJL99Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CJL99Doc diagnostics

#ifdef _DEBUG
void CJL99Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJL99Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJL99Doc commands
