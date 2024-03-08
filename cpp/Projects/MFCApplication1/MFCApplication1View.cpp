
// MFCApplication1View.cpp: CMFCApplication1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#include "Transform.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TRANSLATE_LEFT, &CMFCApplication1View::OnTranslateLeft)
	ON_COMMAND(ID_TRANSLATE_RIGHT, &CMFCApplication1View::OnTranslateRight)
	ON_COMMAND(ID_TRANSLATE_UP, &CMFCApplication1View::OnTranslateUp)
	ON_COMMAND(ID_TRANSLATE_DOWN, &CMFCApplication1View::OnTranslateDown)
	ON_COMMAND(ID_SCALE_BIG, &CMFCApplication1View::OnScaleBig)
	ON_COMMAND(ID_SCALE_SMALL, &CMFCApplication1View::OnScaleSmall)
	ON_COMMAND(ID_ROTATE_CCLOCKWISE, &CMFCApplication1View::OnRotateCclockwise)
	ON_COMMAND(ID_ROTATE_CLOCKWISE, &CMFCApplication1View::OnRotateClockwise)
	ON_COMMAND(ID_REFLECT_XAXIS, &CMFCApplication1View::OnReflectXaxis)
	ON_COMMAND(ID_REFLECT_YAXIS, &CMFCApplication1View::OnReflectYaxis)
	ON_COMMAND(ID_REFLECT_ORIGINPOINT, &CMFCApplication1View::OnReflectOriginpoint)
	ON_COMMAND(ID_SHEAR_XAXIS_FORWARD, &CMFCApplication1View::OnShearXaxisForward)
	ON_COMMAND(ID_SHEAR_XAXIS_REVERSE, &CMFCApplication1View::OnShearXaxisReverse)
	ON_COMMAND(ID_SHEAR_YAXIS_FORWARD, &CMFCApplication1View::OnShearYaxisForward)
	ON_COMMAND(ID_SHEAR_YAXIS_REVERSE, &CMFCApplication1View::OnShearYaxisReverse)
	ON_COMMAND(ID_RESET, &CMFCApplication1View::OnReset)
END_MESSAGE_MAP()

// CMFCApplication1View 构造/析构

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: 在此处添加构造代码
	rectSat = false;
	resetVertices();
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 绘图

void CMFCApplication1View::resetVertices()
{
	(this->vertices).clear();
	vertices.push_back(CPoint(squareP[0][0], squareP[0][1]));
	vertices.push_back(CPoint(squareP[1][0], squareP[1][1]));
	vertices.push_back(CPoint(squareP[2][0], squareP[2][1]));
	vertices.push_back(CPoint(squareP[3][0], squareP[3][1]));
	return;
}

void CMFCApplication1View::SetRect(CDC* pDC)
{
	GetClientRect(&this->rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(this->rect.Width(), this->rect.Height());
	pDC->SetViewportExt(this->rect.Width(), -this->rect.Height());
	pDC->SetViewportOrg(this->rect.Width() / 2, this->rect.Height() / 2);
	this->rect.OffsetRect(-this->rect.Width() / 2, -this->rect.Height() / 2);
	return;
}

void CMFCApplication1View::DrawCoordinateSystem(CDC *pDC)
{
	CPen newPen, * pOldPen;
	int hRect = (this->rect).Height(), wRect = (this->rect).Width();
	newPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(-hRect / 2, 0);
	pDC->LineTo(hRect / 2, 0);
	pDC->MoveTo(0, -wRect / 2);
	pDC->LineTo(0, wRect / 2);
	pDC->SelectObject(pOldPen);
	return;
}

void CMFCApplication1View::DrawShape(CDC* pDC)
{
	CPen newPen, * pOldPen;
	CPoint point0, point1 = this->vertices[0];
	int sizeV = (this->vertices).size();
	newPen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&newPen);
	for (int i = 1; i < sizeV;i++) {
		point0 = point1;
		point1 = this->vertices[i];
		pDC->MoveTo(point0);
		pDC->LineTo(point1);
	}
	pDC->MoveTo(point1);
	pDC->LineTo(this->vertices[0]);
	pDC->SelectObject(pOldPen);
	return;
}

void CMFCApplication1View::translateVerticesWithDraw(int numArg)
{
	int size = (this->vertices).size();
	for (int i = 0; i < size; i++) {
		this->vertices[i] = TransformMatrix::translate(this->vertices[i], translateArgs[numArg][0], translateArgs[numArg][1]);
	}
	RedrawWindow();
	return;
}

void CMFCApplication1View::scaleVerticesWithDraw(int numArg)
{
	int size = (this->vertices).size();
	for (int i = 0; i < size; i++) {
		this->vertices[i] = TransformMatrix::scale(this->vertices[i], scaleArgs[numArg][0], scaleArgs[numArg][1]);
	}
	RedrawWindow();
	return;
}

void CMFCApplication1View::rotateVerticesWithDraw(int numArg)
{
	int size = (this->vertices).size();
	for (int i = 0; i < size; i++) {
		this->vertices[i] = TransformMatrix::rotateA(this->vertices[i], rotateArgs[numArg]);
	}
	RedrawWindow();
	return;
}

void CMFCApplication1View::reflectVerticesWithDraw(int numArg)
{
	int size = (this->vertices).size();
	for (int i = 0; i < size; i++) {
		this->vertices[i] = TransformMatrix::scale(this->vertices[i], reflectArgs[numArg][0], reflectArgs[numArg][1]);
	}
	RedrawWindow();
	return;
}

void CMFCApplication1View::shearVerticesWithDraw(int numArg)
{
	int size = (this->vertices).size();
	for (int i = 0; i < size; i++) {
		this->vertices[i] = TransformMatrix::shear(this->vertices[i], shearArgs[numArg][0], shearArgs[numArg][1]);
	}
	RedrawWindow();
	return;
}

void CMFCApplication1View::resetVerticesWithDraw()
{
	this->resetVertices();
	RedrawWindow();
	return;
}

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (!(this->rectSat))this->SetRect(pDC);
	this->DrawCoordinateSystem(pDC);
	this->DrawShape(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication1View 打印

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序


void CMFCApplication1View::OnTranslateLeft()
{
	this->translateVerticesWithDraw(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnTranslateRight()
{
	this->translateVerticesWithDraw(1);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnTranslateUp()
{
	this->translateVerticesWithDraw(2);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnTranslateDown()
{
	this->translateVerticesWithDraw(3);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnScaleBig()
{
	this->scaleVerticesWithDraw(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnScaleSmall()
{
	this->scaleVerticesWithDraw(1);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnRotateCclockwise()
{
	this->rotateVerticesWithDraw(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnRotateClockwise()
{
	this->rotateVerticesWithDraw(1);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnReflectXaxis()
{
	this->reflectVerticesWithDraw(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnReflectYaxis()
{
	this->reflectVerticesWithDraw(1);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnReflectOriginpoint()
{
	this->reflectVerticesWithDraw(2);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnShearXaxisForward()
{
	this->shearVerticesWithDraw(0);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnShearXaxisReverse()
{
	this->shearVerticesWithDraw(1);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnShearYaxisForward()
{
	this->shearVerticesWithDraw(2);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnShearYaxisReverse()
{
	this->shearVerticesWithDraw(3);
	// TODO: 在此添加命令处理程序代码
}


void CMFCApplication1View::OnReset()
{
	this->resetVerticesWithDraw();
	// TODO: 在此添加命令处理程序代码
}
