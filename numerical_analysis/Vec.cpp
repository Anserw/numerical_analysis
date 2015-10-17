#include "stdafx.h"
#include "Vec.h"
#include "math.h"

namespace na {
	Vec::Vec()
	{
	}

	Vec::Vec(const int l)
	{
		width = 1;
		height = l;
		items_sum = l;
		length = l;
		data = new double[items_sum];
	}

	Vec::Vec(const Vec& a)
	{
		width = 1;
		height = a.height;
		items_sum = height;
		length = a.length;
		data = new double[items_sum];
		for (int i = 0; i < length; i++) {
			data[i] = a.data[i];
		}
	}

	Vec::Vec(const Mat& a)
	{
		width = 1;
		height = a.height;
		items_sum = height;
		length = height;
		data = new double[items_sum];
		for (int i = 0; i < length; i++) {
			data[i] = a.data[i];
		}
	}

	Vec::~Vec()
	{
	}

	void Vec::resize(int l)
	{
		delete data;
		length = l;
		height = l;
		items_sum = l;
		data = new double[l];
	}

	double Vec::norm1()
	{
		double ret;
		ret = 0;
		for (int i = 0; i < length; i++) {
			ret += abs(getItem(i, 0));
		}
		return ret;
	}

	double Vec::norm2()
	{
		double ret, temp;
		ret = 0;
		for (int i = 0; i < length; i++) {
			temp = getItem(i, 0);
			ret += temp * temp;
		}
		ret = sqrt(ret);
		return ret;
	}

	double Vec::normi()
	{
		double ret = -1, temp;
		for (int i = 0; i < length; i++) {
			temp = abs(getItem(i, 0));
			if (temp > ret) {
				ret = temp;
			}
		}
		return ret;
	}

	double& Vec::operator[](int index)
	{
		return data[index];
	}

}

