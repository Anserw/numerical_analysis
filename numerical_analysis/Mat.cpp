#include "stdafx.h"
#include "Mat.h"

using namespace na;

Mat::Mat()
{
	width = 0;
	height = 0;
	items_sum = 0;
	data = NULL;
}

Mat::Mat(int w, int h)
{
	width = w;
	height = h;	
	items_sum = w*h;
	data = new double[items_sum];
}

void Mat::resize(int w, int h)
{
	delete(data);
	width = w;
	height = h;
	items_sum = w*h;
	data = new double[items_sum];
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

void Mat::zero(void)
{
	for (int i = 0; i < items_sum; i++) {
		data[i] = 0;
	}
}

int Mat::getIndex(int x, int y) const
{
	return x*width + y;
}

int Mat::getIndex(int x, int y, int a_width)
{
	return x*a_width + y;
}

int Mat::getX(int index) const
{
	return index / width;
}

int Mat::getY(int index) const
{
	return index % width;
}

double Mat::getItem(int x, int y) const
{
	return data[getIndex(x, y)];
}

void Mat::setItem(int x, int y, double val)
{
	data[getIndex(x, y)] = val;
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
		std::cout << "Error: Can't - them!" << std::endl;
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

Mat operator*(const Mat& a, const Mat& b)
{
	if (a.width != b.height ) {
		std::cout << "Error: Can't * them!" << std::endl;
		return Mat();
	}
	else {
		Mat ret(b.width, a.height);		
		double temp;
		for (int i = 0; i < a.height;i++) {
			for (int j = 0; j < b.width; j++) {
				temp = 0;
				for (int k = 0; k < a.width; k++) {					
					temp += a.getItem(i, k) * b.getItem(i, k);
				}
				ret.setItem(i, j, temp);
			}
		}
		return ret;
	}
}

double* Mat::operator [](int index)
{
	return data+index*width;
}