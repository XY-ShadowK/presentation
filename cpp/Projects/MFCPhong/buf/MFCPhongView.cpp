
// MFCPhongView.cpp: CMFCPhongView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCPhong.h"
#endif

#include "MFCPhongDoc.h"
#include "MFCPhongView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCPhongView

IMPLEMENT_DYNCREATE(CMFCPhongView, CView)

BEGIN_MESSAGE_MAP(CMFCPhongView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCPhongView 构造/析构

CMFCPhongView::CMFCPhongView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCPhongView::~CMFCPhongView()
{
}

BOOL CMFCPhongView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCPhongView 绘图

CRect CMFCPhongView::SetRect(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(), rect.Height());
	pDC->SetViewportExt(rect.Width(), -rect.Height());
	pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);
	return rect;
}

void CMFCPhongView::SetFactor()
{
	this->backgroundLight = MRGB(1.0, 1.0, 1.0);
	this->material = MMaterial(MRGB(0.175, 0.012, 0.012), MRGB(0.614, 0.041, 0.041), MRGB(1.0, 1.0, 1.0), 30.0);
	this->lightsources.push_back(MLight(MRGB(1.0, 1.0, 1.0), MRGB(1.0, 1.0, 1.0), MVector(vector<double>{1000, 1000, 1000}), 1.0, 0.0000001, 0.00000001));
	this->viewPoint = MVector(vector<double>{600, 0, 0});
}

void CMFCPhongView::PaintRound(CDC* pDC, CRect rect, CDC& memDC)
{
	CBitmap newBitmap, * pOldBitmap;
	memDC.CreateCompatibleDC(pDC);
	newBitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBitmap = memDC.SelectObject(&newBitmap);
	memDC.SetMapMode(MM_ANISOTROPIC);
	memDC.SetWindowExt(rect.Width(), rect.Height());
	memDC.SetViewportExt(rect.Width(), -rect.Height());
	memDC.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	this->ScanPhongRound(&memDC);
	pDC->BitBlt(-rect.Width() / 2, -rect.Height() / 2, rect.Width(), rect.Height(), &memDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY);
	memDC.SelectObject(pOldBitmap);
	newBitmap.DeleteObject();
}

void CMFCPhongView::ScanPhongRound(CDC* pDC)
{
	int upperBound = (int)radiusSpace;
	double r2 = radiusRound * radiusRound, x,y2,z2;
	MRGB colorFactor;
	COLORREF color = RGB(0, 0, 0);
	MVector loc,vV,vN;
	for (double z = -upperBound; z <= upperBound; z++)
		for (double y = -upperBound; y <= upperBound; y++) {
			y2 = y * y;
			z2 = z * z;
			if (y2 + z2 > r2) {
				pDC->SetPixelV(y, z, color);
				continue;
			}
			x = sqrt(r2 - z2 - y2);
			loc = MVector(vector<double>{x, y, z});
			vV = this->viewPoint - loc;
			vV.unitalize();
			vN = loc;
			vN.unitalize();
			colorFactor = this->material.getKA() * this->backgroundLight;
			for (auto& it : this->lightsources)
				colorFactor = colorFactor + getLightShader(it, this->material, loc, vV, vN);
			pDC->SetPixelV(y, z, colorFactor.getColor());
		}
	
}

void CMFCPhongView::OnDraw(CDC* pDC)
{
	CMFCPhongDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect = this->SetRect(pDC);
	this->SetFactor();
	CDC memDC;
	this->PaintRound(pDC, rect, memDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCPhongView 打印

BOOL CMFCPhongView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCPhongView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCPhongView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCPhongView 诊断

#ifdef _DEBUG
void CMFCPhongView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPhongView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPhongDoc* CMFCPhongView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPhongDoc)));
	return (CMFCPhongDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPhongView 消息处理程序
