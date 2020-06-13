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
	IplImage* img = cvLoadImage("path/to/image");

    // копируем изображения
	IplImage* smoothThree  = cvCloneImage(img);
	IplImage* smoothFive   = cvCloneImage(img);
	IplImage* smoothNine   = cvCloneImage(img);
	IplImage* smoothEleven = cvCloneImage(img);

    // размытие изображений
	cvSmooth(img, smoothThree, CV_GAUSSIAN, 3, 3);
	cvSmooth(img, smoothFive, CV_GAUSSIAN, 5, 5);
	cvSmooth(img, smoothNine, CV_GAUSSIAN, 9, 9);
	cvSmooth(img, smoothEleven, CV_GAUSSIAN, 11, 11);

    // создаем окна
	cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("3х3", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("5х5", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("9х9", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("11х11", CV_WINDOW_AUTOSIZE);

	cvShowImage("original", img);
	cvShowImage("3х3", smoothThree);
	cvShowImage("5х5", smoothFive);
	cvShowImage("9х9", smoothNine);
	cvShowImage("11х11", smoothEleven);

    // ждём нажатия клавиши
	cvWaitKey(0);

    // освобождаем ресурсы
	cvReleaseImage(&img);
	cvDestroyWindow("original");
	cvDestroyWindow("3х3");
	cvDestroyWindow("5х5");
	cvDestroyWindow("9х9");
	cvDestroyWindow("11х11");

	return 0;
}
