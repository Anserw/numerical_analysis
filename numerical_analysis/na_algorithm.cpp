#include "stdafx.h"
#include "na_algorithm.h"

bool solveLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b,
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

bool solveLSEwithSGE(const Mat& A, Vec& x, const Vec& b)
{
	int n;
	if (A.height != b.height) {
		return false;
	}
	n = A.height;
	Mat a(A);
	Vec bb(b);
	Vec b0(b);
	double akk, mik;
	for (int k = 0; k < n-1; k ++ ) {
		akk = a[k][k];
		if (akk == 0) {
			return false;
		}
		for (int i = k+1 ; i < n; i++) {			
			mik = a[i][k] / akk;
			for (int j = k+1; j < n; j++) {				
				a[i][j] -= mik*a[k][j];
			}			
			bb[i] -= mik*bb[k];
		}
	}
	
	x[n - 1] = b0[n - 1] / a[n-1][n-1];
	double temp;
	for (int k = n - 2; k >= 0; k--) {
		temp = 0;
		for (int j = k+1; j < n; j++) {			
			temp += a[k][j] * x[j];
		}		
		x[k] = (b0[k] - temp) / a[k][k];
	}
	return true;
}