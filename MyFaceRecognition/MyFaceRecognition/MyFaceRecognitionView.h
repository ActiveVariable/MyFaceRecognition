
// MyFaceRecognitionView.h : CMyFaceRecognitionView ��Ľӿ�
//

#pragma once


class CMyFaceRecognitionView : public CView
{
protected: // �������л�����
	CMyFaceRecognitionView();
	DECLARE_DYNCREATE(CMyFaceRecognitionView)

// ����
public:
	CMyFaceRecognitionDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMyFaceRecognitionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDetectandcollect();
	afx_msg void OnCsvcreate();
	afx_msg void OnTrain();
	afx_msg void OnRecognize();
};

#ifndef _DEBUG  // MyFaceRecognitionView.cpp �еĵ��԰汾
inline CMyFaceRecognitionDoc* CMyFaceRecognitionView::GetDocument() const
   { return reinterpret_cast<CMyFaceRecognitionDoc*>(m_pDocument); }
#endif

