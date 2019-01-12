Ptr<FaceRecognizer> model;
vector<Mat> preprocessedFaces;
vector<int> faceLabels;
Mat old_prepreprocessedFace;
double old_time = 0;

// Since we have already initialized everything, lets start in Detection mode.
m_mode = MODE_DETECTION;


// Run forever, until the user hits Escape to "break" out of this loop.
while (true) {

	// Grab the next camera frame. Note that you can't modify camera frames.
	Mat cameraFrame;
	videoCapture >> cameraFrame;
	if( cameraFrame.empty() ) {
		cerr << "ERROR: Couldn't grab the next camera frame." << endl;
		exit(1);
	}

	// Get a copy of the camera frame that we can draw onto.
	Mat displayedFrame;
	cameraFrame.copyTo(displayedFrame);

	// Run the face recognition system on the camera image. It will draw some things onto the given image, so make sure it is not read-only memory!
	int identity = -1;

	// Find a face and preprocess it to have a standard size and contrast & brightness.
	Rect faceRect;  // Position of detected face.
	Rect searchedLeftEye, searchedRightEye; // top-left and top-right regions of the face, where eyes were searched.
	Point leftEye, rightEye;    // Position of the detected eyes.
	Mat preprocessedFace = getPreprocessedFace(displayedFrame, faceWidth, faceCascade, eyeCascade1, eyeCascade2, preprocessLeftAndRightSeparately, &faceRect, &leftEye, &rightEye, &searchedLeftEye, &searchedRightEye);

	bool gotFaceAndEyes = false;
	if (preprocessedFace.data)
		gotFaceAndEyes = true;

	// Draw an anti-aliased rectangle around the detected face.
	if (faceRect.width > 0) {
		rectangle(displayedFrame, faceRect, CV_RGB(255, 255, 0), 2, CV_AA);

		// Draw light-blue anti-aliased circles for the 2 eyes.
		Scalar eyeColor = CV_RGB(0,255,255);
		if (leftEye.x >= 0) {   // Check if the eye was detected
			circle(displayedFrame, Point(faceRect.x + leftEye.x, faceRect.y + leftEye.y), 6, eyeColor, 1, CV_AA);
		}
		if (rightEye.x >= 0) {   // Check if the eye was detected
			circle(displayedFrame, Point(faceRect.x + rightEye.x, faceRect.y + rightEye.y), 6, eyeColor, 1, CV_AA);
		}
	}
	// Check if we have detected a face.
	if (gotFaceAndEyes) 
	{

		// Check if this face looks somewhat different from the previously collected face.
		double imageDiff = 10000000000.0;
		if (old_prepreprocessedFace.data) {
			imageDiff = getSimilarity(preprocessedFace, old_prepreprocessedFace);
		}

		// Also record when it happened.
		double current_time = (double)getTickCount();
		double timeDiff_seconds = (current_time - old_time)/getTickFrequency();

		// Only process the face if it is noticeably different from the previous frame and there has been noticeable time gap.
		if ((imageDiff > CHANGE_IN_IMAGE_FOR_COLLECTION) && (timeDiff_seconds > CHANGE_IN_SECONDS_FOR_COLLECTION)) 
		{
			// Also add the mirror image to the training set, so we have more training data, as well as to deal with faces looking to the left or right.
			Mat mirroredFace;
			flip(preprocessedFace, mirroredFace, 1);

			std::string str = format(str2+"\\%d.bmp",j);
			imwrite(str,preprocessedFace);
			j++;
			str = format(str2+"\\%d.bmp",j);
			imwrite(str,mirroredFace);
			// Make a white flash on the face, so the user knows a photo has been taken.
			Mat displayedFaceRegion = displayedFrame(faceRect);
			displayedFaceRegion += CV_RGB(90,90,90);
		}
	}