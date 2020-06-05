// JL14View.h : interface of the CJL14View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JL14VIEW_H__17701D03_FAAD_4FAD_9F04_3BC76E13FBED__INCLUDED_)
#define AFX_JL14VIEW_H__17701D03_FAAD_4FAD_9F04_3BC76E13FBED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJL14View : public CView
{
protected: // create from serialization only
	CJL14View();
	DECLARE_DYNCREATE(CJL14View)

// Attributes
public:
	CJL14Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL14View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJL14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJL14View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JL14View.cpp
inline CJL14Doc* CJL14View::GetDocument()
   { return (CJL14Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL14VIEW_H__17701D03_FAAD_4FAD_9F04_3BC76E13FBED__INCLUDED_)
