#pragma once
#include "Mat.h"
#include "Vec.h"


namespace na {

	enum enum_method{
		//˳���˹��ȥ��
		METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION,

		//����Ԫ�ظ�˹��ȥ��
		METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION,

		//Doolittle�ֽⷨ
		METHOD_DOOLITTLE,

		//ѡ��Ԫ��Doolittle�ֽⷨ
		METHOD_MAJOR_ELEMENT_DOOLITTLE
	};


	bool solveLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b,
		enum_method method = METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION);

	bool solveLSEwithSGE(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithCMEGE(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithDoolittle(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithMEDoolittle(const Mat& A, Vec& x, const Vec& b);
}
