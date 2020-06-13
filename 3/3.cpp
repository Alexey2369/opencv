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
    CvMat *matrix = cvCreateMat(100, 100, CV_8UC3);
	cvZero(matrix);

	for (int j = 5; j <= 20; j++) {
        for (int i = 20; i < 40; i++) {
            (*(cvPtr2D(matrix, j, i)+1)) = (uchar)(255);
        }
	}

	namedWindow("window", CV_WINDOW_AUTOSIZE);
    cvShowImage("window", matrix);

    waitKey(0);

    cvDestroyWindow("window");

    return 0;
}
