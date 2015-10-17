#pragma once
#include "Mat.h"

namespace na {
	class Vec :
		public Mat
	{
	public:
		Vec();
		Vec(const int l);
		Vec(const Vec& a);
		Vec(const Mat& a);
		~Vec();

		void resize(int l);

		double norm1();
		double norm2();
		double normi();

		double& operator [](int index);

	public:
		int length;
	};


}

