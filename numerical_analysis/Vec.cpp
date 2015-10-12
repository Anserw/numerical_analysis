#include "stdafx.h"
#include "Vec.h"

namespace na {
	Vec::Vec()
	{
	}

	Vec::Vec(int l)
	{
		width = 1;
		height = l;
		items_sum = l;
		length = l;
		data = new double[items_sum];
	}

	Vec::~Vec()
	{
	}

	double& Vec::operator[](int index)
	{
		return data[index];
	}

}

