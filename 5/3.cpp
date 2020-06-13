#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // загружаем изображение
	IplImage* image = cvLoadImage("/path/to/image");

	IplImage* firstImage  = cvCloneImage(image);
	IplImage* secondImage = cvCloneImage(image);
	IplImage* thirdImage  = cvCloneImage(image);

    // создаем окна
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("firstWindow", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("secondWindow", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("thirdWindow", CV_WINDOW_AUTOSIZE);

	cvSmooth(image, firstImage, CV_GAUSSIAN, 9, 9, 1);
	cvSmooth(image, secondImage, CV_GAUSSIAN, 9, 9, 4);
	cvSmooth(image, thirdImage, CV_GAUSSIAN, 9, 9, 6);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 1);
	// cvSmooth(image, secondImage, CV_GAUSSIAN, 0, 0, 4);
	// cvSmooth(image, thirdImage, CV_GAUSSIAN, 0, 0, 6);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 1, 9);
	// cvSmooth(image, secondImage, CV_GAUSSIAN, 0, 0, 1, 9);
	// cvSmooth(image, thirdImage, CV_GAUSSIAN, 0, 0, 1, 9);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 9, 1);
	// cvSmooth(image, secondImage, CV_GAUSSIAN, 0, 0, 9, 1);
	// cvSmooth(image, thirdImage, CV_GAUSSIAN, 0, 0, 9, 1);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 1, 9);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 9, 1);
	// cvSmooth(image, firstImage, CV_GAUSSIAN, 0, 0, 9, 9);
	// cvSmooth(image, secondImage, CV_GAUSSIAN, 0, 0, 0, 0);

	cvShowImage("original", image);
	cvShowImage("firstWindow", firstImage);
	cvShowImage("secondWindow", secondImage);
	cvShowImage("thirdWindow", thirdImage);

    cvWaitKey(0);

    cvDestroyWindow("original");
    cvDestroyWindow("firstWindow");
    cvDestroyWindow("secondWindow");
    cvDestroyWindow("thirdWindow");

	return 0;
}
