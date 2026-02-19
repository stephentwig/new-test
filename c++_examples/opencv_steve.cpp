#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    Mat img = imread("idtech_bg_1.png");
    if (img.empty()) return -1;

    imwrite("output.jpg", img);
    return 0;
}