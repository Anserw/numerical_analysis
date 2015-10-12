#include "stdafx.h"
#include "na_algorithm.h"

namespace na{
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
		case METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION:
			return solveLSEwithCMEGE(A, x, b);
			break;
		case METHOD_DOOLITTLE:
			return solveLSEwithDoolittle(A, x, b);
			break;
		case METHOD_MAJOR_ELEMENT_DOOLITTLE:
			return solveLSEwithMEDoolittle(A, x, b);
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
		for (int k = 0; k < n - 1; k++) {
			akk = a[k][k];
			if (akk == 0) {
				return false;
			}
			for (int i = k + 1; i < n; i++) {
				mik = a[i][k] / akk;
				for (int j = k + 1; j < n; j++) {
					a[i][j] -= mik*a[k][j];
				}
				bb[i] -= mik*bb[k];
			}
		}

		x[n - 1] = b0[n - 1] / a[n - 1][n - 1];
		double temp;
		for (int k = n - 2; k >= 0; k--) {
			temp = 0;
			for (int j = k + 1; j < n; j++) {
				temp += a[k][j] * x[j];
			}
			x[k] = (b0[k] - temp) / a[k][k];
		}
		return true;
	}

	bool solveLSEwithCMEGE(const Mat& A, Vec& x, const Vec& b)
	{
		int n;
		if (A.height != b.height) {
			return false;
		}
		n = A.height;
		Mat a(A);
		Vec bb(b);
		Vec b0(b);
		double akk, mik, maxa, maxik;
		for (int k = 0; k < n - 1; k++) {
			maxa = -1;
			for (int i = k; i < n; i++) {
				if (abs(a[i][k]) > maxa) {
					maxa = abs(a[i][k]);
					maxik = i;
				}
			}
			a.swapLine(k, maxik, k, n);
			bb.swapLine(k, maxik);

			akk = a[k][k];
			if (akk == 0) {
				return false;
			}
			for (int i = k + 1; i < n; i++) {
				mik = a[i][k] / akk;
				for (int j = k + 1; j < n; j++) {
					a[i][j] -= mik*a[k][j];
				}
				bb[i] -= mik*bb[k];
			}
		}

		x[n - 1] = b0[n - 1] / a[n - 1][n - 1];
		double temp;
		for (int k = n - 2; k >= 0; k--) {
			temp = 0;
			for (int j = k + 1; j < n; j++) {
				temp += a[k][j] * x[j];
			}
			x[k] = (b0[k] - temp) / a[k][k];
		}
		return true;
	}

	bool solveLSEwithDoolittle(const Mat& A, Vec& x, const Vec& b)
	{
		Mat a(A);
		Vec b0(b);
		int n;
		double temp;
		n = a.width;
		for (int k = 0; k < n; k++) {
			for (int j = k; j < n; j++) {
				temp = 0;
				for (int t = 0; t < k; t++) {
					temp += a[k][t] * a[t][j];
				}
				a[k][j] -= temp;
			}

			for (int i = k + 1; i < n; i++) {
				temp = 0;
				for (int t = 0; t < k; t++) {
					temp += a[i][t] * a[t][k];
				}
				a[i][k] = (a[i][k] - temp) / a[k][k];
			}
		}
		Vec y(n);
		y[0] = b0[0];
		for (int i = 1; i < n; i++) {
			temp = 0;
			for (int t = 0; t < i; t++) {
				temp += a[i][t] * y[t];
			}
			y[i] = b0[i] - temp;
		}
		x[n - 1] = y[n - 1] / a[n - 1][n - 1];
		for (int i = n - 2; i >= 0; i--) {
			temp = 0;
			for (int t = i + 1; t < n; t++) {
				temp += a[i][t] * x[t];
			}
			x[i] = (y[i] - temp) / a[i][i];
		}
		return true;
	}

	bool solveLSEwithMEDoolittle(const Mat& A, Vec& x, const Vec& b)
	{
		Mat a(A);
		Vec b0(b);
		int n;
		double temp;
		n = a.width;
		Vec s(n);
		Vec M(n);		
		double maxsi;
		for (int k = 0; k < n; k++) {
			maxsi = -1;
			for (int i = k; i < n; i++) {
				temp = 0;
				for (int t = 0; t < k; t++) {
					temp += a[i][t] * a[t][k];
				}
				s[i] = a[i][k] - temp;
				if (abs(s[i]) > maxsi) {
					maxsi = abs(s[i]);
					M[k] = i;
				}
			}
			if (M[k] != k) {
				a.swapLine(k, M[k], 0, k - 1);
				a.swapLine(k, M[k], k, n - 1);
				s.swapLine(k, M[k]);
			}
			a[k][k] = s[k];
			temp = 0;
			for (int j = k + 1; j < n; j++) {
				temp = 0;
				for (int t = 0; t < k; t ++ ) {
					temp += a[k][t] * a[t][j];
				}
				a[k][j] = a[k][j] - temp;
			}
			for (int i = k + 1; i < n; i++) {
				a[i][k] = s[i] / a[k][k];
			}						
		}
		
		for (int k = 0; k < n - 1; k++) {
			b0.swapLine(k, M[k]);
		}
		

		Vec y(n);
		y[0] = b0[0];
		for (int i = 1; i < n; i++) {
			temp = 0;
			for (int t = 0; t < i; t++) {
				temp += a[i][t] * y[t];
			}
			y[i] = b0[i] - temp;
		}
		x[n - 1] = y[n - 1] / a[n - 1][n - 1];
		for (int i = n - 2; i >= 0; i--) {
			temp = 0;
			for (int t = i + 1; t < n; t++) {
				temp += a[i][t] * x[t];
			}
			x[i] = (y[i] - temp) / a[i][i];
		}
		return true;
	}
}

