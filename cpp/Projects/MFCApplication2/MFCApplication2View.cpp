
// MFCApplication2View.cpp: CMFCApplication2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PAINT_BEZIER, &CMFCApplication2View::OnPaintBezier)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication2View 构造/析构

CMFCApplication2View::CMFCApplication2View() noexcept
{
	// TODO: 在此处添加构造代码
	isBezierPainting = false;
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication2View 绘图

void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCApplication2View::DrawHighlightPoint(CPoint point)
{
	CDC* pDC = GetDC();
	CBrush * pOldBrush;
	pOldBrush = (CBrush*)pDC->SelectStockObject(BLACK_BRUSH);
	pDC->MoveTo(point);
	pDC->Ellipse(point.x - 2, point.y - 2, point.x + 2, point.y + 2);
	pDC->SelectObject(pOldBrush);
	ReleaseDC(pDC);
}

void CMFCApplication2View::DrawLine(CPoint p1, CPoint p2)
{
	CDC* pDC = GetDC();
	CPen * pOldPen;
	pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);
}

void CMFCApplication2View::DrawBezier()
{
	CDC* pDC = GetDC();
	CPen NewPen, * pOldPen;
	NewPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(this->controlPoint[0]);
	double x, y, Bnit;
	int size = (this->controlPoint).size();
	for (int t = 0; t <= 100; t++) {
		x = 0.0;
		y = 0.0;
		for (int i = 0; i < size; i++) {
			Bnit = (this->mathTools).getBernstein(size - 1, i, t);
			x += (double)this->controlPoint[i].x * Bnit;
			y += (double)this->controlPoint[i].y * Bnit;
		}
		pDC->LineTo(round(x), round(y));
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);
}

// CMFCApplication2View 打印

BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication2View 诊断

#ifdef _DEBUG
void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication2View 消息处理程序


void CMFCApplication2View::OnPaintBezier()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(L"左键添加控制点，右键启动Bezier曲线绘制", L"提示", MB_OK);
	RedrawWindow();
	this->isBezierPainting = true;
	(this->controlPoint).clear();
}

void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (this->isBezierPainting) {
		(this->controlPoint).push_back(point);
		int size = (this->controlPoint).size();
		if (size >= MAX_NUM_CONTROL_POINT)
			this->isBezierPainting = false;
		this->DrawHighlightPoint(point);
		if (size > 1)
			this->DrawLine(this->controlPoint[size - 2], point);
	}
	else MessageBox(L"控制点数量已达上限，请单击右键启动Bezier曲线绘制", L"提示", MB_OK);
	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplication2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	this->isBezierPainting = false;
	if (!(this->controlPoint).empty())
		this->DrawBezier();
	CView::OnRButtonDown(nFlags, point);
}