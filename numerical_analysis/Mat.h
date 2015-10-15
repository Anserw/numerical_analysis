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
		void print();

		friend Mat operator+(const Mat& a, const Mat& b);
		friend Mat operator-(const Mat& a, const Mat& b);
		friend Mat operator*(const Mat& a, const Mat& b);
		double* operator [](int index);

	public:
		int width, height, items_sum;
		double *data;
	private:
		
		
	};
	
}


