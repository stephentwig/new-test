#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    Mat img = imread("idtech_bg_1.png");
    Mat gray;

    cvtColor(img, gray, COLOR_BGR2GRAY);
    imwrite("gray.jpg", gray);

    return 0;
}