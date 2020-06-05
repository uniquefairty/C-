// JL14Doc.h : interface of the CJL14Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JL14DOC_H__99ACB6CA_B61F_4229_98B7_4F4D1E2E50DE__INCLUDED_)
#define AFX_JL14DOC_H__99ACB6CA_B61F_4229_98B7_4F4D1E2E50DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CJL14Doc : public CDocument
{
protected: // create from serialization only
	CJL14Doc();
	DECLARE_DYNCREATE(CJL14Doc)

// Attributes
public:
	BOOL m_OperateType;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJL14Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJL14Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJL14Doc)
	afx_msg void OnPclear();
	afx_msg void OnPpaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JL14DOC_H__99ACB6CA_B61F_4229_98B7_4F4D1E2E50DE__INCLUDED_)
