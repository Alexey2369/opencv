#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	int radius = 1;

	IplImage* firstImage  = cvLoadImage("/path/to/first/image");
	IplImage* secondImage = cvLoadImage("/path/to/second/image");

    CvSize* firstImageSize  = cvSize(firstImage->width, firstImage->height);
    CvSize* secondImageSize = cvSize(secondImage->width, secondImage->height);

	IplImage* firstGrayImage  = cvCreateImage(firstImageSize, IPL_DEPTH_8U, 1);
	IplImage* secondGrayImage = cvCreateImage(secondImageSize, IPL_DEPTH_8U, 1);

	cvConvertImage(firstImage, firstGrayImage, CV_BGR2GRAY);
	cvConvertImage(secondImage, secondGrayImage, CV_BGR2GRAY);

    IplImage* difference = cvCloneImage(firstGrayImage);

    // a
    cvAbsDiff(firstGrayImage, secondGrayImage, difference);

	IplImage* dilateImage = cvCloneImage(firstGrayImage);
	IplImage* morphImage  = cvCloneImage(secondGrayImage);

	IplImage* temporary = cvCreateImage(cvSize(firstGrayImage->width, firstGrayImage->height), IPL_DEPTH_8U, 1);

	IplConvKernel* kernel = cvCreateStructuringElementEx(
	    radius * 2 + 1,
	    radius * 2 + 1,
	    radius,
	    radius,
	    CV_SHAPE_ELLIPSE
	);

	cvDilate(difference, dilateImage, Kern, 2);

    cvNamedWindow("firstImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("secondImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("firstGrayImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("secondGrayImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("difference", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("dilateImage", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("morphImage", CV_WINDOW_AUTOSIZE);

	cvShowImage("firstImage", firstImage);
	cvShowImage("secondImage", secondImage);
	cvShowImage("firstGrayImage", firstGrayImage);
	cvShowImage("secondGrayImage", secondGrayImage);
	cvShowImage("difference", difference);

	cvThreshold(gray, difference, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 3);

	cvDilate(difference, dilateImage, Kern, 5);

	cvMorphologyEx(dilateImage, morphImage, temporary, kernel, CV_MOP_OPEN, 5);

	cvShowImage("dilateImage", dilateImage);
	cvShowImage("morphImage", morphImage);

	cvReleaseStructuringElement(&kernel);
	cvWaitKey(0);

	cvDestroyWindow("firstImage");
    cvDestroyWindow("secondImage");
    cvDestroyWindow("firstGrayImage");
    cvDestroyWindow("secondGrayImage");
    cvDestroyWindow("difference");
    cvDestroyWindow("dilateImage");
    cvDestroyWindow("morphImage");

	return 0;
}
