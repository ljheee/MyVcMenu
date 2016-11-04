
// MyVcMenuView.cpp : CMyVcMenuView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyVcMenu.h"
#endif

#include "MyVcMenuDoc.h"
#include "MyVcMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyVcMenuView

IMPLEMENT_DYNCREATE(CMyVcMenuView, CView)

BEGIN_MESSAGE_MAP(CMyVcMenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMyVcMenuView 构造/析构

CMyVcMenuView::CMyVcMenuView()
{
	// TODO:  在此处添加构造代码

}

CMyVcMenuView::~CMyVcMenuView()
{
}

BOOL CMyVcMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyVcMenuView 绘制

void CMyVcMenuView::OnDraw(CDC* /*pDC*/)
{
	CMyVcMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMyVcMenuView 打印

BOOL CMyVcMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyVcMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMyVcMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMyVcMenuView 诊断

#ifdef _DEBUG
void CMyVcMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMyVcMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVcMenuDoc* CMyVcMenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVcMenuDoc)));
	return (CMyVcMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyVcMenuView 消息处理程序


void CMyVcMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//此方式，快捷菜单显示位置不对
	CMenu* menu_bar = AfxGetMainWnd()->GetMenu();
	CMenu* file_menu = menu_bar->GetSubMenu(0);    
	ASSERT(file_menu);

	//ClientToScreen(&point);
	file_menu->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, point.x, 
	   point.y, this);


	CView::OnRButtonDown(nFlags, point);
}
