#pragma once


// CTrainDlg �Ի���

class CTrainDlg : public CDialog
{
	DECLARE_DYNAMIC(CTrainDlg)

public:
	CTrainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTrainDlg();

// �Ի�������
	enum { IDD = IDD_Train };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
