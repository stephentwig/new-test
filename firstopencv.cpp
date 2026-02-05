#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace cv;

int main() {
    Mat img = Mat::zeros(500, 500, CV_8UC3);

    rectangle(img, Point(50, 50), Point(200, 200), Scalar(0, 255, 0), 3);
    circle(img, Point(300, 300), 50, Scalar(255, 0, 0), -1);
    putText(img, "So cool OpenCV", Point(100, 450),
        FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

    std::string out = "shapes_3.png";
    if (imwrite(out, img)) {
        std::cout << "Saved image to " << out << std::endl;
        return 0;
    } else {
        std::cerr << "Failed to save image to " << out << std::endl;
        return 1;
    }
}
