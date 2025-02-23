// JL99Doc.h : interface of the CJL99Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JL99DOC_H__B9F7A8CA_4F14_44C7_BCF7_1787ED3573B5__INCLUDED_)
#define AFX_JL99DOC_H__B9F7A8CA_4F14_44C7_BCF7_1787ED3573B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJL99Doc : public CDocument
{
protected: // create from serialization only
	CJL99Doc();
	DECLARE_DYNCREATE(CJL99Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL99Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJL99Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJL99Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL99DOC_H__B9F7A8CA_4F14_44C7_BCF7_1787ED3573B5__INCLUDED_)
