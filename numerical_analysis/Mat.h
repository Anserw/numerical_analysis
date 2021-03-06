#pragma once

#include <iostream>
#include <string>

namespace na {
	class Mat
	{
	public:
		Mat();
		Mat(const Mat& a);
		Mat(int w, int h);
		~Mat();

		bool init(double *input_data);
		bool init(const std::string& input_s);

		void zero(void);
		void resize(int w, int h);		
		void cut(int w, int h);
		void cut(int x1, int y1, int x2, int y2);
		void T();
		void swapLine(int l1, int l2);
		void swapLine(int l1, int l2, int startIndex, int endIndex);

		inline int getIndex(int x, int y) const;
		static inline int getIndex(int x, int y, int a_width);
		inline int getX(int index) const;
		inline int getY(int index) const;

		double getItem(int x, int y) const;
		void setItem(int x, int y, double val);

		double det();
		double det(int x, int y, int dim);
		double norm1();
		double norm2();
		double normi();
		double normF();

		double eigenValueMax(const double accurate = 0.0001);
		double eigenValueMin(const double accurate = 0.00001);
		double* eigenValues(double e=0.001, int L=1000);

		void hessenberg();

		void print();

		friend Mat& operator+(const Mat& a, const Mat& b);
		friend Mat& operator-(const Mat& a, const Mat& b);
		friend Mat& operator*(const Mat& a, const Mat& b);
		friend Mat& operator*(const Mat& a, const double b);
		friend Mat& operator/(const Mat& a, const double& b);
		double* operator [](int index);
		Mat& operator=(Mat& a);

	public:
		int width, height, items_sum;
		double *data;
	private:
		
		
	};

	class MatBandCompreesed :
		public Mat
	{
	public:
		MatBandCompreesed();
		MatBandCompreesed(const Mat& a, int s, int r);

		inline int getIndex(int x, int y) const;

	public:
		int m, n, r, s;
	};
	

	
}


