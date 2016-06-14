
// Vezba1View.cpp : implementation of the CVezba1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Vezba1.h"
#endif

#include "Vezba1Doc.h"
#include "Vezba1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVezba1View

IMPLEMENT_DYNCREATE(CVezba1View, CView)

BEGIN_MESSAGE_MAP(CVezba1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CVezba1View construction/destruction

CVezba1View::CVezba1View()
{
	// TODO: add construction code here

}

CVezba1View::~CVezba1View()
{
}

BOOL CVezba1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVezba1View drawing

void CVezba1View::OnDraw(CDC* pDC)
{
	CVezba1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	CPen newPen, *oldPen;
	CBrush newBrush, *oldBrush;

	newBrush.CreateSolidBrush(RGB(100,220,200));
	newPen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

	oldBrush = pDC->SelectObject(&newBrush);
	oldPen = pDC->SelectObject(&newPen);
	

	CRect rect1;
	rect1.SetRect(100, 100, 300, 300);
	pDC->Rectangle(rect1);

	CPoint triangle1[3] = {
	CPoint(75,100),
	CPoint(325,100),
	CPoint(200,0)
	};
	pDC->Polygon(triangle1,3);

	CPoint triangle2[3] = {
		CPoint(75,300),
		CPoint(325,300),
		CPoint(200,400)
	};
	pDC->Polygon(triangle2, 3);


	CRect rectEl1, rectEl2, rectEl3;
	rectEl1.SetRect(285,135,315,165);
	newBrush.DeleteObject();
	newBrush.CreateSolidBrush(RGB(255, 0, 0));
	pDC->SelectObject(&newBrush);
	pDC->Ellipse(rectEl1);

	rectEl2.SetRect(285, 185, 315, 215);
	newBrush.DeleteObject();
	newBrush.CreateSolidBrush(RGB(255,255,0));
	pDC->SelectObject(&newBrush);
	pDC->Ellipse(rectEl2);

	rectEl3.SetRect(285, 235, 315, 265);
	newBrush.DeleteObject();
	newBrush.CreateSolidBrush(RGB(0,255,0));
	pDC->SelectObject(&newBrush);
	pDC->Ellipse(rectEl3);

	pDC->SelectObject(oldPen);
	newPen.DeleteObject();
	pDC->SelectObject(oldBrush);
	newBrush.DeleteObject();
	
}


// CVezba1View printing

BOOL CVezba1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVezba1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVezba1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CVezba1View diagnostics

#ifdef _DEBUG
void CVezba1View::AssertValid() const
{
	CView::AssertValid();
}

void CVezba1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVezba1Doc* CVezba1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVezba1Doc)));
	return (CVezba1Doc*)m_pDocument;
}
#endif //_DEBUG


// CVezba1View message handlers
