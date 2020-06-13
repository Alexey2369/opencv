#include "\opencv\build\include\opencv\cv.h"
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include "opencv/cv.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv/highgui.h"
#include "opencv2/imgproc.hpp"
#include <stdio.h>
#include <conio.h>
#include "windows.h"

using namespace cv;
using namespace std;


int main(int argc, char* argv[])
{
    IplImage* frame = 0, clonedFrame = 0;
    Mat firstImage = 0, secondImage = 0, thirdImage = 0;

	CvCapture* video = cvCreateFileCapture("/path/to/video");

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);

	while (frame = cvQueryFrame(video)) {
		clonedFrame = cvCloneImage(frame);

		firstImage  = cvarrToMat(frame);
		secondImage = cvarrToMat(clonedFrame);
		thirdImage  = cvarrToMat(clonedFrame);

		cvtColor(firstImage, secondImage, CV_RGB2GRAY);

		Canny(secondImage, thirdImage, 50, 100, 5);

		imshow("original", firstImage);
		imshow("gray", secondImage);

		char c = cvWaitKey(33);

		if (c == 27) {
			break;
		}
	}

	cvReleaseCapture(&video);

	cvDestroyWindow("original");
	cvDestroyWindow("gray");

	return 0;
}
