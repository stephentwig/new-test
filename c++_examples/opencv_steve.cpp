#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_default.xml");

    Mat img = imread("/workspaces/new-test/c++_examples/group_picture.jpg");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    std::vector<Rect> faces;
    face_cascade.detectMultiScale(gray, faces);

    for (auto face : faces)
        rectangle(img, face, Scalar(0,255,0), 2);

    imwrite("faces.jpg", img);
    return 0;
}