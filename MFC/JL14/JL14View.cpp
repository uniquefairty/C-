// JL14View.cpp : implementation of the CJL14View class
//

#include "stdafx.h"
#include "JL14.h"

#include "JL14Doc.h"
#include "JL14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJL14View

IMPLEMENT_DYNCREATE(CJL14View, CView)

BEGIN_MESSAGE_MAP(CJL14View, CView)
	//{{AFX_MSG_MAP(CJL14View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJL14View construction/destruction

CJL14View::CJL14View()
{
	// TODO: add construction code here

}

CJL14View::~CJL14View()
{
}

BOOL CJL14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CJL14View drawing

void CJL14View::OnDraw(CDC* pDC)
{
	CJL14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;//矩形
	CBrush WhiteBrush;
	CBrush RedBrush;
	CBrush GreenBrush;
	CBrush BlueBrush;
	CBrush BlackBrush;
	CBrush YellowBrush;

	WhiteBrush.CreateSolidBrush(RGB(255,255,255));
    RedBrush.CreateSolidBrush(RGB(255,0,0));
    GreenBrush.CreateSolidBrush(RGB(0,255,0));
    BlueBrush.CreateSolidBrush(RGB(0,0,255));
    BlackBrush.CreateSolidBrush(RGB(0,0,0));
    YellowBrush.CreateSolidBrush(RGB(255,255,0));
	GetClientRect(&rect);
	if(pDoc->m_OperateType)
	{//绘制蓝色环
		pDC->SelectObject(BlueBrush);
		pDC->Ellipse(50,50,100,100);
		pDC->SelectObject(WhiteBrush);
		pDC->Ellipse(54,54,96,96);
    //绘制黄色环
		pDC->SelectObject(YellowBrush);
		pDC->Ellipse(76,76,126,125);
		pDC->SelectObject(WhiteBrush);
		pDC->Ellipse(80,79,122,121);
		pDC->SelectObject(BlackBrush);
        pDC->Ellipse(104,50,154,100);
        pDC->SelectObject(WhiteBrush);
        pDC->Ellipse(108,54,150,96);
        pDC->SelectObject(GreenBrush);
        pDC->Ellipse(130,75,180,125);
        pDC->SelectObject(WhiteBrush);
        pDC->Ellipse(134,79,176,121);
        pDC->SelectObject(RedBrush);
        pDC->Ellipse(158,50,208,100);
        pDC->SelectObject(WhiteBrush);
        pDC->Ellipse(162,54,204,96);
        pDC->TextOut(80,190,"支持奥运事业!");
	}
	else
	{
		//将整个视图涂成白色，清除图案
		pDC->SelectObject(WhiteBrush);
		pDC->FillRect(&rect,&WhiteBrush);
	}
    //销毁画刷，释放系统资源
	WhiteBrush.DeleteObject();
	RedBrush.DeleteObject();
	GreenBrush.DeleteObject();
	BlueBrush.DeleteObject();
	BlackBrush.DeleteObject();
	YellowBrush.DeleteObject();


}

/////////////////////////////////////////////////////////////////////////////
// CJL14View printing

BOOL CJL14View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CJL14View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CJL14View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CJL14View diagnostics

#ifdef _DEBUG
void CJL14View::AssertValid() const
{
	CView::AssertValid();
}

void CJL14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CJL14Doc* CJL14View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJL14Doc)));
	return (CJL14Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJL14View message handlers
