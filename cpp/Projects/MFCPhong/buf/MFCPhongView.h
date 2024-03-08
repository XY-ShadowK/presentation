
// MFCPhongView.h: CMFCPhongView 类的接口
//

#pragma once

using std::vector;

class CMFCPhongView : public CView
{
protected: // 仅从序列化创建
	CMFCPhongView() noexcept;
	DECLARE_DYNCREATE(CMFCPhongView)

// 特性
public:
	CMFCPhongDoc* GetDocument() const;

// 操作
private:
	MRGB backgroundLight;
	MMaterial material;
	vector<MLight> lightsources;
	MVector viewPoint;
	static constexpr double radiusSpace = 250.0;
	static constexpr double radiusRound = 200.0;
public:
	CRect SetRect(CDC* pDC);
	void SetFactor();
	void PaintRound(CDC* pDC, CRect rect, CDC& memDC);
	void ScanPhongRound(CDC* pDC);
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
	virtual ~CMFCPhongView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCPhongView.cpp 中的调试版本
inline CMFCPhongDoc* CMFCPhongView::GetDocument() const
   { return reinterpret_cast<CMFCPhongDoc*>(m_pDocument); }
#endif

