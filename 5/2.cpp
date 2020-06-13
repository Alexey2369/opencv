#include <iostream>
#include "/opencv/build/include/opencv/highgui.h"
#include "/opencv/build/include/opencv/cv.h"
#include "/opencv/build/include/opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // создаем одноканальное изображение 100x100
	Mat img = Mat::zeros(100, 100, CV_8UC3);

    // устанавливаем центральный пиксель равным 255
	img.at<Vec3b>(50, 50)[0] = 255;
	img.at<Vec3b>(50, 50)[1] = 255;
	img.at<Vec3b>(50, 50)[2] = 255;

    // создаем изображения
	IplImage* original   = cvCloneImage(&(IplImage)img);
	IplImage* smoothFive = cvCloneImage(&(IplImage)img);
	IplImage* smoothNine = cvCloneImage(&(IplImage)img);

    // создаем окна
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("5х5", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("9х9", CV_WINDOW_AUTOSIZE);

    // размытие изображений
	cvSmooth(image, smoothFive, CV_GAUSSIAN, 5, 5);
	cvSmooth(image, smoothNine, CV_GAUSSIAN, 9, 9);

    // выводим изображения
	cvShowImage("original", original);
	cvShowImage("5х5", smoothFive);
	cvShowImage("9x9", smoothNine);

	waitKey(0);

	cvDestroyWindow("original");
    cvDestroyWindow("5х5");
    cvDestroyWindow("9х9");

	return 0;
}
