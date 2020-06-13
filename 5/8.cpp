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

	Mat image = Mat::zeros(100, 100, CV_8UC3);

	randu(image, Scalar(0, 0, 0), Scalar(255, 255, 255));

	IplImage* loadedImage = cvLoadImage(pathToImage);
	IplImage* morphImage = cvCloneImage(loadedImage);

    IplImage* temporary = cvCreateImage(cvSize(image->width, image->height), IPL_DEPTH_8U, 1);

	IplConvKernel* kernel = cvCreateStructuringElementEx(
	    radius * 2 + 1,
	    radius * 2 + 1,
	    radius,
	    radius,
	    CV_SHAPE_ELLIPSE
	);

    cvNamedWindow("withRandomColors", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("originalImage", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("morphImage", CV_WINDOW_AUTOSIZE);

	imshow("withRandomColors", image);
	imwrite(pathToImage, image);

	cvMorphologyEx(loadedImage, morphImage, temporary, kernel, CV_MOP_OPEN, 5);

	cvShowImage("originalImage", loadedImage);
	cvShowImage("morphImage", morphImage);

    cvReleaseStructuringElement(&kernel);

	waitKey(0);

    cvDestroyWindow("withRandomColors");
    cvDestroyWindow("originalImage");
    cvDestroyWindow("morphImage");

	return 0;
}
