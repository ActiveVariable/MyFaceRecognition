#pragma once


// CDetectAndCollectDlg �Ի���

class CDetectAndCollectDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetectAndCollectDlg)

public:
	CDetectAndCollectDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetectAndCollectDlg();

// �Ի�������
	enum { IDD = IDD_DetectAndCollect };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
