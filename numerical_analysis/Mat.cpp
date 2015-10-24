#include "stdafx.h"
#include "Mat.h"
#include <iomanip>
#include "math.h"

namespace na{

	Mat::Mat()
	{
		width = 0;
		height = 0;
		items_sum = 0;
		data = NULL;
	}

	Mat::Mat(const Mat& a)
	{
		width = a.width;
		height = a.height;
		items_sum = a.items_sum;
		data = new double[items_sum];
		for (int i = 0; i < items_sum; i++) {
			data[i] = a.data[i];
		}
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

	void Mat::T()
	{
		double temp;
		int a, b;
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				a = getIndex(i, j, width);
				b = getIndex(j, i, height);
				temp = data[a];
				data[a] = data[b];
				data[b] = temp;
			}
		}
		temp = width;
		width = height;
		height = temp;
	}

	Mat::~Mat()
	{
	}

	bool Mat::init(double* input_data)
	{
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				data[getIndex(i, j)] = input_data[getIndex(i, j)];
			}
		}
		return true;
	}

	bool Mat::init(const std::string& input_s)
	{
		int count = 0, l, p = 1;
		double curr, mul = 1;
		bool flag = false;
		bool dot = false;
		char ch;
		l = input_s.length();
		for (int i = 0; i < l; i++) {
			ch = input_s[i];
			if (ch == ' ' || ch == ',') {
				if (flag) {
					data[count++] = curr*p;
					if (count >= items_sum) {
						return true;
					}
					curr = 0;
					flag = false;
					dot = false;
					mul = 1;
					p = 1;
				}
			}
			else if (ch >= '0' && ch <= '9') {
				if (flag) {
					if (dot) {
						mul = mul / 10;
						curr += mul * (ch - '0');
					}
					else {
						curr = curr * 10 + (ch - '0');
					}
				}
				else {
					flag = true;
					dot = false;
					mul = 1;
					curr = ch - '0';
				}
			}
			else if (ch == '.') {
				if (dot) {
					return false;
				}
				else {
					dot = true;
				}
			}
			else if (ch == '-') {
				p = -1;
			}
			else{
				return false;
			}
		}
		if (flag) {
			data[count++] = curr*p;
		}
		return true;
	}

	void Mat::zero(void)
	{
		for (int i = 0; i < items_sum; i++) {
			data[i] = 0;
		}
	}

	void Mat::swapLine(int l1, int l2)
	{
		swapLine(l1, l2, 0, width);
	}

	void Mat::swapLine(int l1, int l2, int startIndex, int endIndex)
	{
		double temp;
		if (startIndex < 0) {
			startIndex = 0;
		}
		if (endIndex > width) {
			endIndex = width;
		}
		for (int i = startIndex; i < endIndex; i++) {
			temp = data[getIndex(l1, i)];
			data[getIndex(l1, i)] = data[getIndex(l2, i)];
			data[getIndex(l2, i)] = temp;
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

	void Mat::print()
	{
		std::setprecision(3);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << std::setw(8) << data[getIndex(i, j)] << ' ';
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	Mat operator+(const Mat& a, const Mat& b)
	{
		if (a.width != b.width || a.height != b.height) {
			std::cout << "Error: Can't add them!" << std::endl;
			return Mat();
		}
		else {
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
		if (a.width != b.height) {
			std::cout << "Error: Can't * them!" << std::endl;
			return Mat();
		}
		else {
			Mat ret(b.width, a.height);
			double temp;
			for (int i = 0; i < a.height; i++) {
				for (int j = 0; j < b.width; j++) {
					temp = 0;
					for (int k = 0; k < a.width; k++) {
						temp += a.getItem(i, k) * b.getItem(k, j);
					}
					ret.setItem(i, j, temp);
				}
			}
			return ret;
		}
	}

	Mat operator/(const Mat& a, const double& b)
	{
		Mat ret(a);
		for (int i = 0; i < ret.items_sum; i++) {
			ret.data[i] /= b;
		}
		return ret;
	}

	double* Mat::operator [](int index)
	{
		return data + index*width;
	}



	
	double Mat::det()
	{
		if (width != height) {
			std::cout << "Error occured during compute det!" << std::endl;
		}
		return det(0, 0, width);
	}

	double MDET(double **a, unsigned dim);
	double Mat::det(int x, int y, int dim)
	{
		double ret;
		double **a = (double**)malloc(sizeof(double*)*dim);
		for (int i = 0; i < dim; i++) {
			a[i] = data + (y + i)*width + x;
		}
		ret = MDET(a, dim);
		free(a);
		return ret;
	}

	double Mat::norm1()
	{
		double ret = -1, temp;
		int n;
		n = height;
		for (int j = 0; j < n; j++) {
			temp = 0;
			for (int i = 0; i < n; i++) {
				temp += abs(getItem(i, j));
			}
			if (temp > ret) {
				ret = temp;
			}
		}
		return ret;
	}

	double Mat::norm2()
	{
		//TODO
		return 0;
	}

	double Mat::normi()
	{
		double ret = -1, temp;
		int n;
		n = height;
		for (int i = 0; i < n; i++) {
			temp = 0;
			for (int j = 0; j < n; j++) {
				temp += abs(getItem(i, j));
			}
			if (temp > ret) {
				ret = temp;
			}
		}
		return ret;
	}

	double Mat::normF()
	{
		double ret=0, temp;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				temp = getItem(i, j);
				ret += temp*temp;
			}
		}
		ret = sqrt(ret);
		return ret;
	}

	//double eigenValueMax(const Mat a, double accurate)
	//{
	//	double nk_1;
	//	int width;
	//	width = a.width;
	//	Vec u(width);
	//	for (int i = 0; i < width; i++){
	//		u[i] = 1;
	//	}
	//	Vec ut(u);
	//	ut.T();
	//	Mat u2;
	//	Vec y;
	//	double b, b1;
	//	for (int k = 1;; k++) {
	//		u2 = ut * u;
	//		nk_1 = sqrt(u2[0][0]);
	//		y = u / nk_1;
	//		u = a * y;
	//		y.T();
	//		b = (y * u).data[0];
	//		if (k > 1 && (abs(b - b1) / b <= accurate)) {
	//			return b;
	//		}else {
	//			b1 = b;
	//		}
	//	}
	//	return 0;
	//}


	// ³ýÒò×Ó¾ØÕó
	void MCOF(double **a,
		double **cof_ij,
		unsigned row,
		unsigned col,
		unsigned dim_a)
	{
		unsigned i = 0, j = 0;
		unsigned ii = 0, jj = 0;
		for (i = 0; i<dim_a; i++){
			if (i == row) continue;
			for (j = 0; j<dim_a; j++){
				if (j == col) continue;
				cof_ij[ii][jj] = a[i][j];
				jj++;
			}
			ii++;
			jj = 0;
		}
	}

	// ==============================
	// Çó2½×¾ØÕó determinte
	double MDET2(double **a)
	{
		return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
	}


	// ==============================
	// Çó3½×¾ØÕó determinte
	double MDET3(double **a)
	{
		double x = 0.0, y = 0.0, z = 0.0;
		x = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
		y = a[1][0] * (a[0][1] * a[2][2] - a[0][2] * a[2][1]);
		z = a[2][0] * (a[0][1] * a[1][2] - a[0][2] * a[1][1]);
		return (x - y + z);
	}

	// ==============================
	// Çó¾ØÕó determinte
	double MDET(double **a,
		unsigned dim)
	{
		unsigned i;
		double x = 0.0;
		double sum = 0.0;

		double **b = (double**)malloc(sizeof(double*)*dim);
		for (i = 0; i<dim; i++) b[i] = (double*)malloc(sizeof(double)*dim);

		if (dim == 1) return a[0][0];
		if (dim == 2) return MDET2(a);
		if (dim == 3) return MDET3(a);
		for (i = 0; i<dim; i++)
		{
			MCOF(a, b, 0, i, dim);
			if (i % 2 == 0) x = 1.0;
			else x = -1.0;
			sum += a[0][i] * MDET(b, dim - 1) * x;
		}
		for (i = 0; i<dim; i++) free(b[i]);
		free(b);
		return sum;
	}

	MatBandCompreesed::MatBandCompreesed(const Mat& a, int a_s, int a_r)
	{
		width = a.width;
		height = a.height;
		items_sum = a.items_sum;

		r = a_r;
		s = a_s;
		n = width;
		m = r + s + 1;

		data = new double[m*n];
		int t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				t = i - j + s + 1;
				if ( t >= 0 && t < m) {
					data[t*n + j] = a.getItem(i, j);
				}
			}
		}		
	}

	int MatBandCompreesed::getIndex(int x, int y) const
	{
		return (x - y + s)*width + y;
	}
}
