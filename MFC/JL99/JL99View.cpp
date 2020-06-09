// JL99View.cpp : implementation of the CJL99View class
//

#include "stdafx.h"
#include "JL99.h"

#include "JL99Doc.h"
#include "JL99View.h"

#include "ComtDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJL99View

IMPLEMENT_DYNCREATE(CJL99View, CView)

BEGIN_MESSAGE_MAP(CJL99View, CView)
	//{{AFX_MSG_MAP(CJL99View)
	ON_COMMAND(ID_TEST_COMCTL, OnTestComctl)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL99View construction/destruction

CJL99View::CJL99View()
{
	// TODO: add construction code here

}

CJL99View::~CJL99View()
{
}

BOOL CJL99View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJL99View drawing

void CJL99View::OnDraw(CDC* pDC)
{
	CJL99Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CJL99View printing

BOOL CJL99View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJL99View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJL99View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJL99View diagnostics

#ifdef _DEBUG
void CJL99View::AssertValid() const
{
	CView::AssertValid();
}

void CJL99View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJL99Doc* CJL99View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJL99Doc)));
	return (CJL99Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJL99View message handlers

void CJL99View::OnTestComctl() 
{
	// TODO: Add your command handler code here
	CComtDlg dlg;
	if(dlg.DoModal()!=IDOK)  return ;
	Invalidate();
	UpdateWindow();
	CClientDC dc(this);
	CPen penNew,*ppenOld;
	penNew.CreatePen(PS_SOLID,dlg.m_nLine,RGB(0,0,255));
	ppenOld=dc.SelectObject(&penNew);
	//dc.Ellipse(0,0,200,200);
	dc.Ellipse(0,0,2*dlg.m_nRadius,2*dlg.m_nRadius);
	dc.SelectObject(ppenOld);

}
