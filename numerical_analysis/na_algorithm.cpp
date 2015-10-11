#include "stdafx.h"
#include "na_algorithm.h"

bool solveLinearSimultaneousEquations(const Mat& A, Mat& x, const Mat& b,
	enum_method method)
{
	if (x.width != 1 || x.height != A.width) {
		x.resize(1, A.width);
	}
	switch (method)
	{
	case METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION:
		return solveLSEwithSGE(A, x, b);
		break;
	default:
		break;
	}
	return false;
}

bool solveLSEwithSGE(const Mat& A, Mat& x, const Mat& b)
{
	int n;
	if (A.height != b.height) {
		return false;
	}
	n = A.height;
	Mat a(A);
	Mat bb(b);
	double akk, mik;
	for (int k = 0; k < n-1; k ++ ) {
		akk = a.getItem(k, k);
		if (akk == 0) {
			return false;
		}
		for (int i = k+1 ; i < n; i++) {
			mik = a.getItem(i, k) / akk;
			for (int j = k+1; j < n; j++) {
				a.setItem(i, j, a.getItem(i, j) - mik*a.getItem(k, j));
			}
			bb.setItem(i, 0, bb[i] - mik*bb[k]);
		}
	}

	x.setItem(n-1, 0, b[n-1] / a.getItem(n-1, n-1));
	double temp;
	for (int k = n - 2; k >= 0; k--) {
		temp = 0;
		for (int j = k+1; j < n; j++) {
			temp += a.getItem(k, j) * x[j];
		}
		x.setItem(k, 0, (b[k] - temp) / a.getItem(k, k));
	}
	return true;
}