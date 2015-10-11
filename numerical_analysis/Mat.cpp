#include "stdafx.h"
#include "Mat.h"

using namespace na;

Mat::Mat()
{
}

Mat::Mat(int w, int h)
{
	width = w;
	height = h;
	data = new double[w*h];
}


Mat::~Mat()
{
}

bool Mat::init(double* input_data)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			data[getIndex(i,j)] = input_data[getIndex(i,j)];
		}
	}
	return true;
}

int Mat::getIndex(int x, int y)
{
	return y*width + x;
}


Mat operator+(const Mat& a, const Mat& b)
{
	if (a.width != b.width || a.height != b.height) {
		std::cout << "Error: Can't add them!" << std::endl;
		return Mat();
	}else {
		Mat ret(a.width, a.height);
		for (int i = 0; i < a.width*a.height; i++) {
			ret.data[i] = a.data[i] + b.data[i];
		}
		return ret;
	}
}

Mat operator-(const Mat& a, const Mat& b)
{
	if (a.width != b.width || a.height != b.height) {
		std::cout << "Error: Can't add them!" << std::endl;
		return Mat();
	}
	else {
		Mat ret(a.width, a.height);
		for (int i = 0; i < a.width*a.height; i++) {
			ret.data[i] = a.data[i] - b.data[i];
		}
		return ret;
	}
}