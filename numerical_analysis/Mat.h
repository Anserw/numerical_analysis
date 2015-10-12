#pragma once
#include <iostream>

namespace na {
	class Mat
	{
	public:
		Mat();
		Mat(int w, int h);
		~Mat();

		bool init(double *input_data);
		void zero(void);
		void resize(int w, int h);		

		inline int getIndex(int x, int y) const;
		static inline int getIndex(int x, int y, int a_width);
		inline int getX(int index) const;
		inline int getY(int index) const;

		double getItem(int x, int y) const;
		void setItem(int x, int y, double val);

		friend Mat operator +(const Mat& a, const Mat& b);
		friend Mat operator -(const Mat& a, const Mat& b);
		friend Mat operator *(const Mat& a, const Mat& b);
		double* operator [](int index);

	public:
		int width, height, items_sum;
		double *data;
	private:
		
		
	};

}


