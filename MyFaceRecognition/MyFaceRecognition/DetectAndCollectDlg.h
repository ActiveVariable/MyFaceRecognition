#pragma once


// CDetectAndCollectDlg 对话框

class CDetectAndCollectDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetectAndCollectDlg)

public:
	CDetectAndCollectDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetectAndCollectDlg();

// 对话框数据
	enum { IDD = IDD_DetectAndCollect };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
