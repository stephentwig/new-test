#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main() {
    Mat img = imread("idtech_bg.png");
    if (img.empty()) {
        std::cerr << "Failed to load input image idtech_bg.png" << std::endl;
        return 1;
    }

    Mat gray, edges;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Canny(gray, edges, 100, 200);

    std::string out = "bandw.png";
    if (imwrite(out, edges)) {
        std::cout << "Saved image to " << out << std::endl;
        return 0;
    } else {
        std::cerr << "Failed to save image to " << out << std::endl;
        return 2;
    }
}
