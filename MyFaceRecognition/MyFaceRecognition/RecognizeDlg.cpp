// RecognizeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyFaceRecognition.h"
#include "RecognizeDlg.h"
#include "afxdialogex.h"

#include<iostream>
#include <conio.h>
#include"opencv2/opencv.hpp"
#include "string_replace.h"
#include "preprocessFace.h"
#include "InitDetector.h"
#include "recognition.h"
using namespace std;
using namespace cv;
// CRecognizeDlg 对话框

IMPLEMENT_DYNAMIC(CRecognizeDlg, CDialog)

CRecognizeDlg::CRecognizeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecognizeDlg::IDD, pParent)
{

}

CRecognizeDlg::~CRecognizeDlg()
{
}

void CRecognizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRecognizeDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CRecognizeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CRecognizeDlg 消息处理程序


void CRecognizeDlg::OnBnClickedOk()
{
	const float UNKNOWN_PERSON_THRESHOLD = 0.5f;

	CascadeClassifier faceCascade;
	CascadeClassifier eyeCascade1;
	CascadeClassifier eyeCascade2;
	InitDetector(faceCascade, eyeCascade1, eyeCascade2);

	Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	modelPCA->load("MyFacePCAModel.xml");

	int img_num = 1;

	int predictPCA = 0;

	Point text_lb = (-1000,200);

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
		double similarity = 10000;
		if (gotFaceAndEyes && !preprocessedFace.empty())
		{
			Mat reconstructedFace;
			reconstructedFace = reconstructFace(modelPCA, preprocessedFace);
			similarity = getSimilarity(preprocessedFace, reconstructedFace);
			text_lb = Point(leftEye.x,leftEye.y);
			if (similarity < UNKNOWN_PERSON_THRESHOLD) 
			{
				predictPCA = modelPCA->predict(preprocessedFace);
			}
			else
			{
				predictPCA = 5;
			}
		}
		
		std::string name;
		switch (predictPCA)
		{
			case 1:
				name = "FanXueLi";
				putText(displayedFrame,name,text_lb,FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
				break;
			case 2:
				name = "GuoQinHua";
				putText(displayedFrame,name,text_lb,FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
				break;
			case 3:
				name = "HeZiYi";
				putText(displayedFrame,name,text_lb,FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
				break;
			default :
				name = "NoBody";
				putText(displayedFrame,name,text_lb,FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255));
				break;
		}

		char key = waitKey(100);
		imshow("recognition", displayedFrame);

		if (key == 'q')
		{
			destroyWindow("recognition");
			break;
		}
	}
}
