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

		inline int getIndex(int x, int y);

		friend Mat operator +(const Mat& a, const Mat& b);
		friend Mat operator -(const Mat& a, const Mat& b);

	public:
		int width, height;
		double *data;
	private:
		
		
	};

}


