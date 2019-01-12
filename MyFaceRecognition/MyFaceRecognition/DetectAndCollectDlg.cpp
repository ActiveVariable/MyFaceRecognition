// DetectAndCollectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFaceRecognition.h"
#include "DetectAndCollectDlg.h"
#include "afxdialogex.h"

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

// Include OpenCV's C++ Interface
#include "opencv2/opencv.hpp"

// Include the rest of my code!
#include "detectObject.h"     
#include "preprocessFace.h"     
#include "recognition.h"     
#include "ImageUtils.h" 
#include "string_replace.h"
#include "InitDetector.h"
using namespace cv;
using namespace std;



// CDetectAndCollectDlg 对话框

IMPLEMENT_DYNAMIC(CDetectAndCollectDlg, CDialog)

CDetectAndCollectDlg::CDetectAndCollectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetectAndCollectDlg::IDD, pParent)
{

}

CDetectAndCollectDlg::~CDetectAndCollectDlg()
{
}

void CDetectAndCollectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDetectAndCollectDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CDetectAndCollectDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDetectAndCollectDlg 消息处理程序


void CDetectAndCollectDlg::OnBnClickedOk()
{
	CString OriginalImagePath;
	GetDlgItem(IDC_OriginalImagePath)->GetWindowText(OriginalImagePath);
	string_replace(string(OriginalImagePath), "\\", "\\\\");
	
	int img_num = GetDlgItemInt(IDC_ImageNum) + 1;

	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;
	InitDetector(faceCascade, eyeCascade1, eyeCascade2);

	VideoCapture capture(0);
	while (1) 
	{
		Mat cameraFrame;
		capture >> cameraFrame;
		if( cameraFrame.empty() ) 
		{
			cerr << "ERROR: Couldn't grab the next camera frame." << endl;
			exit(1);
		}

		Mat displayedFrame;
		cameraFrame.copyTo(displayedFrame);

		const int faceWidth = 70;
		const bool preprocessLeftAndRightSeparately = true;
		Rect faceRect;
		Rect searchedLeftEye, searchedRightEye;
		Point leftEye, rightEye;  
		Mat preprocessedFace = getPreprocessedFace(displayedFrame, faceWidth, faceCascade, eyeCascade1, eyeCascade2, preprocessLeftAndRightSeparately, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

		bool gotFaceAndEyes = false;
		if (preprocessedFace.data)
		{
			gotFaceAndEyes = true;
		}

		if (faceRect.width > 0) 
		{

			rectangle(displayedFrame, faceRect, CV_RGB(255, 255, 0), 2, CV_AA);

			Scalar eyeColor = CV_RGB(0,255,255);
			if (leftEye.x >= 0) 
			{   
				circle(displayedFrame, Point(faceRect.x + leftEye.x, faceRect.y + leftEye.y), 6, eyeColor, 1, CV_AA);
			}
			if (rightEye.x >= 0) 
			{   
				circle(displayedFrame, Point(faceRect.x + rightEye.x, faceRect.y + rightEye.y), 6, eyeColor, 1, CV_AA);
			}
		}
		char key = waitKey(100);
		imshow("windowName", displayedFrame);
		if (gotFaceAndEyes)
		{
			std::string str = format(OriginalImagePath+"\\%d.bmp",img_num);
			imwrite(str,preprocessedFace);
			img_num++;
		}

		if (key == 'q')
		{
			destroyWindow("windowName");
			break;
		}
	}
}
