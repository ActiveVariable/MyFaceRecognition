#pragma once


// CRecognizeDlg 对话框

class CRecognizeDlg : public CDialog
{
	DECLARE_DYNAMIC(CRecognizeDlg)

public:
	CRecognizeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRecognizeDlg();

// 对话框数据
	enum { IDD = IDD_Recognize };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
