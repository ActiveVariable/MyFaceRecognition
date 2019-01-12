CascadeClassifier faceCascade;
CascadeClassifier eyeCascade1;
CascadeClassifier eyeCascade2;
InitDetector(faceCascade, eyeCascade1, eyeCascade2);

Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
model->load("MyFacePCAModel.xml");

VideoCapture capture(0);
Mat frame;
Mat gray;