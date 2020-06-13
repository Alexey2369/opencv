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
	Mat image = imread("1.jpg", CV_LOAD_IMAGE_COLOR);

    cvCircle(image, cvPoint(100, 100), 50, CV_RGB(255, 255, 255), 1, 8);

    namedWindow("window", CV_WINDOW_AUTOSIZE);
    imshow("window", image);

	waitKey(0);

    cvDestroyWindow("window");

	return 0;
}
