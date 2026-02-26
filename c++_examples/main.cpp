#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    // 1️⃣ Load the image
    Mat img = imread("group1.png");
    if (img.empty()) {
        cout << "Could not load image\n";
        return -1;
    }

    // 2️⃣ Convert to grayscale (face detection works on gray)
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // 3️⃣ Load Haar cascade classifier
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Could not load cascade file\n";
        return -1;
    }

    // 4️⃣ Detect faces
    vector<Rect> faces;
    faceCascade.detectMultiScale(gray, faces);

    // 5️⃣ Draw rectangles around detected faces
    for (size_t i = 0; i < faces.size(); i++) {
        rectangle(img, faces[i], Scalar(0,255,0), 3);
    }

    // 6️⃣ Save result (headless mode)
    imwrite("faces_detected.jpg", img);

    cout << "Faces detected: " << faces.size() << endl;

    return 0;
}