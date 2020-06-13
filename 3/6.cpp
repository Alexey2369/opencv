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
	IplImage* image     = cvLoadImage("/path/to/image", 1);
	IplImage* newImage  = cvCreateImageHeader(cvSize(20, 30), image->depth, image->nChannels);
	newImage->origin    = image->origin;
	newImage->widthStep = image->widthStep;

	cvNot(image, newImage);

	namedWindow("newImage", CV_WINDOW_AUTOSIZE);
	cvShowImage("newImage", newImage);

	cvWaitKey(0);

    cvDestroyWindow("newImage");

	return 0;
}
