#pragma once


// CTrainDlg 对话框

class CTrainDlg : public CDialog
{
	DECLARE_DYNAMIC(CTrainDlg)

public:
	CTrainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTrainDlg();

// 对话框数据
	enum { IDD = IDD_Train };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
