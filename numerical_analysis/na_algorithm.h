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
		METHOD_MAJOR_ELEMENT_DOOLITTLE,

		//���Ƿֽⷨ
		METHOD_TRIANGULAR_DECOMPOSITION,

		//Jacobi������
		METHOD_JACOBI_ITERATION
	};


	bool solveLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b,
		enum_method method = METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION);

	bool solveLSEwithSGE(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithCMEGE(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithDoolittle(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithMEDoolittle(const Mat& A, Vec& x, const Vec& b);

	bool solveLSEwithJacobiIteration(const Mat& A, Vec& x, const Vec& b);

	bool solveBandLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b, int s, int r);

	bool solve3BLSEwithSpeedupMethod(const Mat& A, Vec& x, const Vec& b);

	template<class T>inline T max(T a, T b);

	template<class T>inline T max(T a, T b, T c);

	template<class T>inline T min(T a, T b);

	template<class T>inline T min(T a, T b, T c);
}
