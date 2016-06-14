
// TabletView.h : interface of the CTabletView class
//

#pragma once


class CTabletView : public CView
{
protected: // create from serialization only
	CTabletView();
	DECLARE_DYNCREATE(CTabletView)

// Attributes
public:
	CTabletDoc* GetDocument() const;

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
	virtual ~CTabletView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TabletView.cpp
inline CTabletDoc* CTabletView::GetDocument() const
   { return reinterpret_cast<CTabletDoc*>(m_pDocument); }
#endif

