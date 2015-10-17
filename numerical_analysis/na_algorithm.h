#pragma once
#include "Mat.h"
#include "Vec.h"


namespace na {

	enum enum_method{
		//顺序高斯消去法
		METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION,

		//列主元素高斯消去法
		METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION,

		//Doolittle分解法
		METHOD_DOOLITTLE,

		//选主元的Doolittle分解法
		METHOD_MAJOR_ELEMENT_DOOLITTLE,

		//三角分解法
		METHOD_TRIANGULAR_DECOMPOSITION,

		//Jacobi迭代法
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
