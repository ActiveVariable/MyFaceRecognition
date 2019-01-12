
// MyFaceRecognitionView.cpp : CMyFaceRecognitionView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMyFaceRecognitionView ����/����

CMyFaceRecognitionView::CMyFaceRecognitionView()
{
	// TODO: �ڴ˴���ӹ������

}

CMyFaceRecognitionView::~CMyFaceRecognitionView()
{
}

BOOL CMyFaceRecognitionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyFaceRecognitionView ����

void CMyFaceRecognitionView::OnDraw(CDC* /*pDC*/)
{
	CMyFaceRecognitionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyFaceRecognitionView ��ӡ


void CMyFaceRecognitionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMyFaceRecognitionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyFaceRecognitionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyFaceRecognitionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CMyFaceRecognitionView ���

#ifdef _DEBUG
void CMyFaceRecognitionView::AssertValid() const
{
	CView::AssertValid();
}

void CMyFaceRecognitionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyFaceRecognitionDoc* CMyFaceRecognitionView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyFaceRecognitionDoc)));
	return (CMyFaceRecognitionDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyFaceRecognitionView ��Ϣ�������


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
