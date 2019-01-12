// TrainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFaceRecognition.h"
#include "TrainDlg.h"
#include "afxdialogex.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<math.h>
#include<string>
#include"opencv2/opencv.hpp"
#include "string_replace.h"

using namespace std;
using namespace cv;

// CTrainDlg 对话框

IMPLEMENT_DYNAMIC(CTrainDlg, CDialog)

CTrainDlg::CTrainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrainDlg::IDD, pParent)
{

}

CTrainDlg::~CTrainDlg()
{
}

void CTrainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTrainDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CTrainDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTrainDlg 消息处理程序

static void read_csv(const std::string &filename,vector<Mat> &images,vector<int> &labels,char separator = ';')
{
	std::ifstream file(filename.c_str(),ifstream::in);
	if (!file)
	{
		std::string error_message = "No Valid Input Was Given";
		CV_Error(CV_StsBadArg,error_message);
	}

	string line,path,classlabel;
	while (getline(file,line))
	{
		stringstream liness(line);
		getline(liness,path,separator);
		getline(liness,classlabel);
		if (!path.empty() && !classlabel.empty())
		{
			images.push_back(imread(path,0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}

}

void CTrainDlg::OnBnClickedOk()
{
	SetDlgItemText(IDC_TrainSucessful,"训练中");

	CString CSVPath1;
	GetDlgItem(IDC_CSVPath1)->GetWindowText(CSVPath1);
	string_replace(string(CSVPath1), "\\", "\\\\");

	CString xmlPath;
	GetDlgItem(IDC_xmlPath)->GetWindowText(xmlPath);
	string_replace(string(xmlPath), "\\", "\\\\");

	string fn_csv = CSVPath1+"\\CSV.txt";

	vector<Mat> images;
	vector<int> labels;

	try
	{
		read_csv(fn_csv,images,labels);
	}
	catch (cv::Exception& e)
	{
		cerr<<"Error Opening File \""<<fn_csv<<"\".Reason:"<< e.msg<<endl;
		exit(1);
	}

	if (images.size() <= 1)
	{
		string error_message = "This demo needs at least 2 images to work.";
		CV_Error(CV_StsError,error_message);
	}

	Mat testSample = images[images.size() - 1];
	int testLabel = labels[labels.size() - 1];
	images.pop_back();
	labels.pop_back();


	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	model->train(images,labels);
	model->save("MyFacePCAModel.xml");
	CopyFile("MyFacePCAModel.xml", xmlPath+"\\MyFacePCAModel.xml", 1);
	int predictedLabel = model->predict(testSample);

	SetDlgItemText(IDC_TrainSucessful,"训练完成");

	waitKey(0);
}
