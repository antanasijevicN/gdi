
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

void CTabletView::OnDraw(CDC* pDC)
{
	CTabletDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(rect);

	//DrawHouse(pDC, 50);
	//DrawMenu(pDC, 100);
	//DrawArrow(pDC, 100);


	
}
void CTabletView::DrawHouse(CDC *pDC, float dx) {

	

	newPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC->SelectObject(&newPen);

	pDC->MoveTo(0, 0.2*dx);
	pDC->LineTo(dx, 0.2*dx);
	pDC->LineTo(0.5*dx, 0);
	pDC->LineTo(0, 0.2*dx);

	pDC->MoveTo(0.1*dx,0.2*dx);
	pDC->LineTo(0.1*dx, dx);
	pDC->LineTo(0.9*dx,dx);
	pDC->LineTo(0.9*dx, 0.2*dx);

	pDC->SelectObject(oldPen);
	newPen.DeleteObject();
}

void CTabletView::DrawMenu(CDC *pDC, float dx) {
	newPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC->SelectObject(&newPen);

	pDC->MoveTo(0, 0);
	pDC->LineTo(dx, 0);
	pDC->LineTo(dx, dx);
	pDC->LineTo(0, dx);
	pDC->LineTo(0, 0);

	pDC->MoveTo(0, 0.25*dx);
	pDC->LineTo(dx, 0.25*dx);
	pDC->MoveTo(0, 0.5*dx);
	pDC->LineTo(dx, 0.5*dx);
	pDC->MoveTo(0, 0.75*dx);
	pDC->LineTo(dx, 0.75*dx);


	pDC->SelectObject(oldPen);
	newPen.DeleteObject();

}
void CTabletView::DrawArrow(CDC *pDC, float dx) {
	newPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldPen = pDC->SelectObject(&newPen);

	float r = 0.9*dx;
	float pi = 3.1415926535897932384626433832795;
	float angleStep = pi / 180;
	float angle = pi;
	pDC->MoveTo(r*sin(angle),dx+r*cos(-angle));
	for (int i = 0; i < 90; i++) {
		pDC->LineTo(r*sin(angle), dx+r*cos(-angle));
		angle -= angleStep;
	}
	pDC->MoveTo(0.2*dx, 0);
	pDC->LineTo(0,0.1*dx);
	pDC->MoveTo(0.2*dx, 0.2*dx);
	pDC->LineTo(0, 0.1*dx);

	pDC->SelectObject(oldPen);
	newPen.DeleteObject();
}
void CTabletView::DrawMagnifier(CDC *pDC, float dx) {}
void CTabletView::DrawDisplay(CDC *pDC, CString sPicName, CRect rcPicture) {}
void CTabletView::DrawTablet(float dx, float dy, CString sName, int fSize, CString sPicName, COLORREF clrFrame) {}

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
