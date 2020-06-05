// JL14Doc.cpp : implementation of the CJL14Doc class
//

#include "stdafx.h"
#include "JL14.h"

#include "JL14Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJL14Doc

IMPLEMENT_DYNCREATE(CJL14Doc, CDocument)

BEGIN_MESSAGE_MAP(CJL14Doc, CDocument)
	//{{AFX_MSG_MAP(CJL14Doc)
	ON_COMMAND(ID_PCLEAR, OnPclear)
	ON_COMMAND(ID_PPAINT, OnPpaint)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL14Doc construction/destruction

CJL14Doc::CJL14Doc()
{
	// TODO: add one-time construction code here
	m_OperateType=FALSE;

}

CJL14Doc::~CJL14Doc()
{
}

BOOL CJL14Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJL14Doc serialization

void CJL14Doc::Serialize(CArchive& ar)
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
// CJL14Doc diagnostics

#ifdef _DEBUG
void CJL14Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJL14Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJL14Doc commands

void CJL14Doc::OnPclear() 
{
	// TODO: Add your command handler code here
	m_OperateType=FALSE;//绘制图案
	UpdateAllViews(NULL);
}

void CJL14Doc::OnPpaint() 
{
	// TODO: Add your command handler code here
	m_OperateType=TRUE;//绘制图案
	UpdateAllViews(NULL);
	
}
