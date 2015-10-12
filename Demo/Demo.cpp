// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../numerical_analysis/na_algorithm.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double l_mat_A[9] = { 8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2 };
	double l_mat_b[3] = { 6.1, 2.3, 1.8 };
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init(l_mat_A);
	b.init(l_mat_b);
	solveLSEwithSGE(A, x, b);
	cout << x[0] << endl << x[1] << endl << x[2] << endl;
	system("pause");
	return 0;
}

