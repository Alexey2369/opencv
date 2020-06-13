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

IplImage* loadedImage = 0, image = 0;

void mouseCallback(int event, int x, int y, int f, void*) {
	image     = loadedImage.clone();
	Vec3b rgb = image.at<Vec3b>(y, x);

    cout << "red" << rgb.val[2] << "green" << rgb.val[1] << "blue" << rgb.val[0] << endl;
}

int main(int argc, char* argv[])
{
	namedWindow("window", CV_WINDOW_AUTOSIZE);

	IplImage* loadedImage = imread("/path/to/image");
	imshow("window", loadedImage);

	setMouseCallback(mouseCallback, onMouse, 0);

	waitKey(0);
	cvDestroyWindow("window");

	return 0;
}
