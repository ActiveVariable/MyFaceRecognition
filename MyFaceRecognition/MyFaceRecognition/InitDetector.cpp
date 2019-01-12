#include "stdafx.h"
#include "InitDetector.h"

using namespace std;
using namespace cv;

const char *faceCascadeFilename = "lbpcascade_frontalface.xml"; 
const char *eyeCascadeFilename1 = "haarcascade_mcs_lefteye.xml";  
const char *eyeCascadeFilename2 = "haarcascade_mcs_righteye.xml";

void InitDetector(CascadeClassifier &faceCascade, CascadeClassifier &eyeCascade1, CascadeClassifier &eyeCascade2)
{
	try 
	{   
		faceCascade.load(faceCascadeFilename);
	} 
	catch (cv::Exception &e) {}
	if ( faceCascade.empty() ) 
	{
		cerr << "ERROR: Could not load Face Detection cascade classifier [" << faceCascadeFilename << "]!" << endl;
		cerr << "Copy the file from your OpenCV data folder (eg: 'C:\\OpenCV\\data\\lbpcascades') into this WebcamFaceRec folder." << endl;
		exit(1);
	}
	cout << "Loaded the Face Detection cascade classifier [" << faceCascadeFilename << "]." << endl;

	try 
	{  
		eyeCascade1.load(eyeCascadeFilename1);
	} 
	catch (cv::Exception &e) {}
	if ( eyeCascade1.empty() ) {
		cerr << "ERROR: Could not load 1st Eye Detection cascade classifier [" << eyeCascadeFilename1 << "]!" << endl;
		cerr << "Copy the file from your OpenCV data folder (eg: 'C:\\OpenCV\\data\\haarcascades') into this WebcamFaceRec folder." << endl;
		exit(1);
	}
	cout << "Loaded the 1st Eye Detection cascade classifier [" << eyeCascadeFilename1 << "]." << endl;

	try 
	{   
		eyeCascade2.load(eyeCascadeFilename2);
	} 
	catch (cv::Exception &e) {}
	if ( eyeCascade2.empty() ) {
		cerr << "Could not load 2nd Eye Detection cascade classifier [" << eyeCascadeFilename2 << "]." << endl;
		// Dont exit if the 2nd eye detector did not load, because we have the 1st eye detector at least.
		//exit(1);
	}
	else
		cout << "Loaded the 2nd Eye Detection cascade classifier [" << eyeCascadeFilename2 << "]." << endl;
}