#include <iostream>
#include "opencv/cv.h"
#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include "/opencv/build/include/opencv/cv.h"

using namespace std;
using namespace cv;

int main() {
    Mat zeros      = Mat::zeros(100, 100, CV_8UC1);
    IplImage image = imread("/path/to/image", CV_LOAD_IMAGE_COLOR);

    zeros(r).copyTo(image);

    cvRectangle(&image, Point(20, 5), Point(40, 20), Scalar(0, 255, 0));

    namedWindow("window", CV_WINDOW_AUTOSIZE);
    imshow("window", image);

    waitKey(0);

    cvDestroyWindow("window");

    return 0;
}
