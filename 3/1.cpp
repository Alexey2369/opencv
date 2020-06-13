#include <iostream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include "/opencv/build/include/opencv2/core/types_c.h"

using namespace std;

int main() {
    // a
    double number                  = -1.3;
    unsigned double unsignedNumber = abs(number);

    cout << "original number" << number << "absolute number" << unsignedNumber << "celled number" << ceil(unsignedNumber) << "rounded number" << round(unsignedNumber) << "floored number" << floor(unsignedNumber);

    waitKey(0);

	return 0;

    // b
    srand(500);

    for (int count = 0; count < 100; ++count) {
        cout << rand() << "\t";
    }

    waitKey(0);

	return 0;

    // c
	CvPoint2D32f cvPoint2D32f(double x, double y);

	CvPoint cvPointFrom32f(CvPoint2D32f point);

    // d
	CvPoint2D32f cvPointTo32f(CvPoint point);

    waitKey(0);

	return 0;
}
