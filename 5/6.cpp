#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;


void bloom(IplImage* image, CvPoint cvPoint)
{
    CvScalar rgbColor = CV_RGB(255, 0, 0);

	CvConnectedComp cvConnectedComp;

	cvFloodFill(
	    image,
	    cvPoint,
	    rgbColor,
		cvScalarAll(10),
		cvScalarAll(10),
		&cvConnectedComp,
		CV_FLOODFILL_FIXED_RANGE + 8,
		0
    );
}

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

	IplImage* dilateImage = cvCloneImage(firstGrayImage);
    IplImage* morphImage  = cvCloneImage(secondGrayImage);

	cvAbsDiff(firstGrayImage, secondGrayImage, difference);

	IplImage* temporary = cvCreateImage(cvSize(firstGrayImage->width, firstGrayImage->height), IPL_DEPTH_8U, 1);

	IplConvKernel* kernel = cvCreateStructuringElementEx(
	    radius * 2 + 1,
	    radius * 2 + 1,
	    radius,
	    radius,
	    CV_SHAPE_ELLIPSE
	);

    cvNamedWindow("firstImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("secondImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("firstGrayImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("secondGrayImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("difference", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("dilateImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("morphImage", CV_WINDOW_AUTOSIZE);

	cvDilate(difference, dilateImage, Kern, 2);

	for (int y = 0; y < morphImage->height; y++) {
		uchar* unsignedChar = (uchar*) (morphImage->imageData + y * morphImage->widthStep);
		for (int x = 0; x < morphImage->width; x++) {
			if (
			    unsignedChar[3 * x] == 255 &&
			    unsignedChar[3 * x + 1] == 255 &&
			    unsignedChar[3 * x + 2] == 255
			) {
				bloom(morphImage, cvPoint(x, y));
			}
		}
	}

    cvShowImage("firstImage", firstImage);
    cvShowImage("secondImage", secondImage);
    cvShowImage("firstGrayImage", firstGrayImage);
    cvShowImage("secondGrayImage", secondGrayImage);
    cvShowImage("difference", difference);

    cvDilate(difference, dilateImage, kernel, 5);

    cvMorphologyEx(morphImage, morphImage, temporary, kernel, CV_MOP_OPEN, 5);

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