#pragma once


// CCSVCreateDlg �Ի���

class CCSVCreateDlg : public CDialog
{
	DECLARE_DYNAMIC(CCSVCreateDlg)

public:
	CCSVCreateDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCSVCreateDlg();

// �Ի�������
	enum { IDD = IDD_CSVCreate };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
