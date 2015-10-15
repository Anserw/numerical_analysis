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

		double& operator [](int index);

	public:
		int length;
	};


}

