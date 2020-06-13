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
	Mat zeros = Mat::zeros(210, 210, CV_8UC1);
	Mat image = imread("/path/to/image", CV_LOAD_IMAGE_COLOR);

	for (int j = 0; j <= 200; j++) {
	    for (int i = 20; i < 200; i++) {
            int x = i + 120;
            int y = j + 10;
            Rect r(x, y, i + 260, i + 30);
            image(r) += CV_RGB(0, 0, 255);
            image(r).copyTo(zeros);
        }
	}

	namedWindow("window", CV_WINDOW_AUTOSIZE);
	imshow("window", zeros);

	cvWaitKey(0);

    cvDestroyWindow("window");

	return 0;
}
