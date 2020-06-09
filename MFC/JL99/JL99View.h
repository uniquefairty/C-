// JL99View.h : interface of the CJL99View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JL99VIEW_H__70F1E7C8_C706_4F1A_8630_D67519C29207__INCLUDED_)
#define AFX_JL99VIEW_H__70F1E7C8_C706_4F1A_8630_D67519C29207__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJL99View : public CView
{
protected: // create from serialization only
	CJL99View();
	DECLARE_DYNCREATE(CJL99View)

// Attributes
public:
	CJL99Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL99View)
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
	virtual ~CJL99View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJL99View)
	afx_msg void OnTestComctl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JL99View.cpp
inline CJL99Doc* CJL99View::GetDocument()
   { return (CJL99Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL99VIEW_H__70F1E7C8_C706_4F1A_8630_D67519C29207__INCLUDED_)
