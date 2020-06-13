#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    string pathToImage = '/path/to/image';
	int radius         = 1;

	IplImage* image = cvLoadImage(pathToImage);

    // a
	Mat firstImage  = imread(pathToImage);
	Mat secondImage = imread(pathToImage);

	Mat difference = firstImage - secondImage;

	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	imshow("original", difference);

    // b, c
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("erodeImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("dilateImage", CV_WINDOW_AUTOSIZE);

	IplImage* erodeImage  = cvCloneImage(image);
	IplImage* dilateImage = cvCloneImage(image);

	IplConvKernel* kernel = cvCreateStructuringElementEx(
	    radius * 2 + 1,
	    radius * 2 + 1,
	    radius,
	    radius,
	    CV_SHAPE_ELLIPSE
	);

	cvErode(image, erode, kernel, 1);
	cvDilate(image, dilate, kernel, 1);

	cvShowImage("erodeImage", erode);
	cvShowImage("dilateImage", dilate);
	cvReleaseStructuringElement(&kernel);

	cvWaitKey(0);

    cvDestroyWindow("original");
    cvDestroyWindow("erodeImage");
    cvDestroyWindow("dilateImage");

	return 0;
}
