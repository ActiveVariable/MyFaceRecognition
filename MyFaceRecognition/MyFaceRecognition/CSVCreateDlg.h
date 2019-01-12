#pragma once


// CCSVCreateDlg 对话框

class CCSVCreateDlg : public CDialog
{
	DECLARE_DYNAMIC(CCSVCreateDlg)

public:
	CCSVCreateDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCSVCreateDlg();

// 对话框数据
	enum { IDD = IDD_CSVCreate };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
