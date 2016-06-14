
// TabletView.cpp : implementation of the CTabletView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tablet.h"
#endif

#include "TabletDoc.h"
#include "TabletView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabletView

IMPLEMENT_DYNCREATE(CTabletView, CView)

BEGIN_MESSAGE_MAP(CTabletView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTabletView construction/destruction

CTabletView::CTabletView()
{
	// TODO: add construction code here

}

CTabletView::~CTabletView()
{
}

BOOL CTabletView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTabletView drawing

void CTabletView::OnDraw(CDC* /*pDC*/)
{
	CTabletDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTabletView printing

BOOL CTabletView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabletView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabletView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTabletView diagnostics

#ifdef _DEBUG
void CTabletView::AssertValid() const
{
	CView::AssertValid();
}

void CTabletView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabletDoc* CTabletView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabletDoc)));
	return (CTabletDoc*)m_pDocument;
}
#endif //_DEBUG


// CTabletView message handlers
