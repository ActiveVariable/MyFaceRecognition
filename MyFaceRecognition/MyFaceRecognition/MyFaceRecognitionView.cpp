
// MyFaceRecognitionView.cpp : CMyFaceRecognitionView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyFaceRecognition.h"
#endif

#include "MyFaceRecognitionDoc.h"
#include "MyFaceRecognitionView.h"
#include "DetectAndCollectDlg.h"
#include "CSVCreateDlg.h"
#include "TrainDlg.h"
#include "RecognizeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyFaceRecognitionView

IMPLEMENT_DYNCREATE(CMyFaceRecognitionView, CView)

BEGIN_MESSAGE_MAP(CMyFaceRecognitionView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMyFaceRecognitionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_DetectAndCollect, &CMyFaceRecognitionView::OnDetectandcollect)
	ON_COMMAND(IDM_CSVCreate, &CMyFaceRecognitionView::OnCsvcreate)
	ON_COMMAND(IDM_Train, &CMyFaceRecognitionView::OnTrain)
	ON_COMMAND(IDM_Recognize, &CMyFaceRecognitionView::OnRecognize)
END_MESSAGE_MAP()

// CMyFaceRecognitionView 构造/析构

CMyFaceRecognitionView::CMyFaceRecognitionView()
{
	// TODO: 在此处添加构造代码

}

CMyFaceRecognitionView::~CMyFaceRecognitionView()
{
}

BOOL CMyFaceRecognitionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyFaceRecognitionView 绘制

void CMyFaceRecognitionView::OnDraw(CDC* /*pDC*/)
{
	CMyFaceRecognitionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMyFaceRecognitionView 打印


void CMyFaceRecognitionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyFaceRecognitionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyFaceRecognitionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyFaceRecognitionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMyFaceRecognitionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMyFaceRecognitionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMyFaceRecognitionView 诊断

#ifdef _DEBUG
void CMyFaceRecognitionView::AssertValid() const
{
	CView::AssertValid();
}

void CMyFaceRecognitionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyFaceRecognitionDoc* CMyFaceRecognitionView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFaceRecognitionDoc)));
	return (CMyFaceRecognitionDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyFaceRecognitionView 消息处理程序


void CMyFaceRecognitionView::OnDetectandcollect()
{
	CDetectAndCollectDlg Dlg;
	Dlg.DoModal();
}


void CMyFaceRecognitionView::OnCsvcreate()
{
	CCSVCreateDlg Dlg;
	Dlg.DoModal();
}


void CMyFaceRecognitionView::OnTrain()
{
	CTrainDlg Dlg;
	Dlg.DoModal();
}


void CMyFaceRecognitionView::OnRecognize()
{
	CRecognizeDlg Dlg;
	Dlg.DoModal();
}
