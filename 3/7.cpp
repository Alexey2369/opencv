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
    double minimum = 0, maximum = 0, thresh = 0;

	IplImage* image = cvLoadImage("/path/to/image");

	IplImage* rgb   = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
	IplImage* red   = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	IplImage* green = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
	IplImage* blue  = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);

	cvCopyImage(image, rgb);

	cvSplit(rgb, red, green, blue, 0);

	IplImage* firstImage  = cvCloneImage(green);
	IplImage* secondImage = cvCloneImage(green);

	cvMinMaxLoc(green, &minimum, &maximum);

	thresh = (unsigned char) ((maximum - minimum) / 2.0);

	cvThreshold(green, firstImage, thresh, 256, CV_THRESH_BINARY);

	namedWindow("firstImage", CV_WINDOW_AUTOSIZE);
	namedWindow("secondImage", CV_WINDOW_AUTOSIZE);

	cvShowImage("firstImage", firstImage);

	cvThreshold(green, secondImage, 0, 256, CV_THRESH_TRUNC);

	cvCmp(green, firstImage, secondImage, CV_CMP_GE);
	cvSubS(green, cvScalar(thresh / 2.0), green, secondImage);

	cvShowImage("secondImage", secondImage);

	cvWaitKey(0);

    cvDestroyWindow("firstImage");
    cvDestroyWindow("secondImage");

	return 0;
}
