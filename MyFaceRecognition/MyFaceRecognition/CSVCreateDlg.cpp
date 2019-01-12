// CSVCreateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyFaceRecognition.h"
#include "CSVCreateDlg.h"
#include "afxdialogex.h"

#include<iostream>
#include<fstream>
#include<stdio.h>
#include "string_replace.h"

using namespace std;

// CCSVCreateDlg �Ի���

IMPLEMENT_DYNAMIC(CCSVCreateDlg, CDialog)

CCSVCreateDlg::CCSVCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSVCreateDlg::IDD, pParent)
{

}

CCSVCreateDlg::~CCSVCreateDlg()
{
}

void CCSVCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCSVCreateDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CCSVCreateDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCSVCreateDlg ��Ϣ�������


void CCSVCreateDlg::OnBnClickedOk()
{
	CString ClassPath;
	GetDlgItem(IDC_ClassPath)->GetWindowText(ClassPath);
	string_replace(string(ClassPath), "\\", "\\\\");

	int RangeBegin;
	RangeBegin = GetDlgItemInt(IDC_RangeBegin);

	int RangeEnd;
	RangeEnd = GetDlgItemInt(IDC_RangeEnd);

	int ImgSumInClass;
	ImgSumInClass = GetDlgItemInt(IDC_ImgSumInClass);

	CString CSVPath;
	GetDlgItem(IDC_CSVPath)->GetWindowText(CSVPath);
	string_replace(string(CSVPath), "\\", "\\\\");

	ofstream in;
	in.open(CSVPath+"\\CSV.txt",ios::trunc);
	for (int i = RangeBegin;i <= RangeEnd;i++)
	{
		for (int j = 1;j <= ImgSumInClass;j++)
		{
			in<<ClassPath+"\\s"<<i<<"\\"<<j<<".bmp;"<<i<<"\n";
		}
	}

	in.close();
}
