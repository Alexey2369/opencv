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

char key;

const string ELLIPSE   = 'e';
const string LINE      = 'l';
const string RECTANGLE = 'r';

using namespace cv;
using namespace std;

// отрисовка фигуры
void draw(IplImage* img, int x, int y)
{
    int radius = 10;

	switch (key) {
	    case ELLIPSE:
		    cvCircle(img, Point(x, y), radius, CV_RGB(250, 0, 0), 1, 8);
		    break;

	    case LINE:
		    cvLine(img, Point(x - radius / 2, y - radius / 2), Point(x + radius / 2, y + radius / 2), CV_RGB(250, 0, 0), 1, 8);
		    break;
	    case RECTANGLE:
		    cvRectangle(img, Point(x - radius, y + radius), Point(x + radius, y - radius), CV_RGB(255, 0, 0), 1, 8);
		    break;
	}
}


// обработчик событий мыши
void mouse(int event, int x, int y, int flags, void* param)
{
	switch (event) {
        case CV_EVENT_MOUSEMOVE:
        case CV_EVENT_LBUTTONUP:
            break;

        case CV_EVENT_LBUTTONDOWN:
            IplImage* img = (IplImage*)param;
            draw(img, x, y);
            break;
	}
}

int main(int argc, char* argv[])
{
	IplImage* image       = cvLoadImage("/path/to/image");
	IplImage* clonedImage = cvCloneImage(img);

	cvNamedWindow("paint", CV_WINDOW_AUTOSIZE);

	// вешаем обработчик мышки
	cvSetMouseCallback("paint", mouse, (void*) image);

	while (key = cvWaitKey(40)) {
		// показываем картинку
		cvCopyImage(image, clonedImage);
		cvShowImage("paint", clonedImage);

		char c = cvWaitKey(33);

		if (c == 27) {
			break;
		}
	}

	cvReleaseImage(&image);
	cvReleaseImage(&clonedImage);
	cvDestroyWindow("paint");

	return 0;
}
