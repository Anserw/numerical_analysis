#pragma once
#include "Mat.h"

namespace na {
	class Vec :
		public Mat
	{
	public:
		Vec();
		Vec(int l);
		Vec(Mat a);
		~Vec();

		void resize(int l);

		double& operator [](int index);

	public:
		int length;
	};


}

