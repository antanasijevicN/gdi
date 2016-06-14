
// Vezba1View.h : interface of the CVezba1View class
//

#pragma once


class CVezba1View : public CView
{
protected: // create from serialization only
	CVezba1View();
	DECLARE_DYNCREATE(CVezba1View)

// Attributes
public:
	CVezba1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVezba1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Vezba1View.cpp
inline CVezba1Doc* CVezba1View::GetDocument() const
   { return reinterpret_cast<CVezba1Doc*>(m_pDocument); }
#endif

