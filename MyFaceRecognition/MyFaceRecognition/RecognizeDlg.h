#pragma once


// CRecognizeDlg �Ի���

class CRecognizeDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecognizeDlg)

public:
	CRecognizeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRecognizeDlg();

// �Ի�������
	enum { IDD = IDD_Recognize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
