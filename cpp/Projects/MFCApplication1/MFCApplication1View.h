
// MFCApplication1View.h: CMFCApplication1View 类的接口
//

#pragma once

using std::vector;

class CMFCApplication1View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication1View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication1View)

// 特性
public:
	CMFCApplication1Doc* GetDocument() const;

// 操作
private:
	static constexpr int squareP[4][2] = { {50,50},{-50,50},{-50,-50},{50,-50} };
	static constexpr int translateArgs[4][2] = { {-2,0},{2,0},{0,2},{0,-2} };
	static constexpr double scaleArgs[2][2] = { {2,2},{0.5,0.5} };
	static constexpr int rotateArgs[2] = { 30,-30 };
	static constexpr int reflectArgs[3][2] = { {1,-1},{-1,1},{-1,-1} };
	static constexpr int shearArgs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
	//static constexpr int 
	bool rectSat;
	CRect rect;
	vector<CPoint> vertices;
public:
	void resetVertices();
	void SetRect(CDC* pDC);
	void DrawCoordinateSystem(CDC* pDC);
	void DrawShape(CDC* pDC);
	void translateVerticesWithDraw(int numArg);
	void scaleVerticesWithDraw(int numArg);
	void rotateVerticesWithDraw(int numArg);
	void reflectVerticesWithDraw(int numArg);
	void shearVerticesWithDraw(int numArg);
	void resetVerticesWithDraw();

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTranslateLeft();
	afx_msg void OnTranslateRight();
	afx_msg void OnTranslateUp();
	afx_msg void OnTranslateDown();
	afx_msg void OnScaleBig();
	afx_msg void OnScaleSmall();
	afx_msg void OnRotateCclockwise();
	afx_msg void OnRotateClockwise();
	afx_msg void OnReflectXaxis();
	afx_msg void OnReflectYaxis();
	afx_msg void OnReflectOriginpoint();
	afx_msg void OnShearXaxisForward();
	afx_msg void OnShearXaxisReverse();
	afx_msg void OnShearYaxisForward();
	afx_msg void OnShearYaxisReverse();
	afx_msg void OnReset();
};

#ifndef _DEBUG  // MFCApplication1View.cpp 中的调试版本
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

