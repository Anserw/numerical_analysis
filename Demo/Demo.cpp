// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../numerical_analysis/na_algorithm.h"
#include <iostream>

using namespace std;
using namespace na;

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
	cout << x[0] << endl << x[1] << endl << x[2] << endl << endl;

	A.resize(5, 5);
	b.resize(5);
	x.resize(5);
	A.init("1 2 3 4 0 5 6 7 8 9 10 11 12 13 14 0 15 16 17 18 0 0 19 20 21");
	b.init("30 115 190 236 242");
	//x.init("1 2 3 4 5");
	//b = A * x;
	//cout << b[0] << endl << b[1] << endl << b[2] << endl << b[3] << endl << b[4] << endl;
	//solveBandLinearSimultaneousEquations(A, x, b, 3, 2);
	//solveLSEwithMEDoolittle(A, x, b);
	//solveLSEwithCMEGE(A, x, b);
	solveLSEwithDoolittle(A, x, b);
	cout << x[0] << endl << x[1] << endl << x[2] << endl << x[3] << endl << x[4] << endl;
	system("pause");
	return 0;
}

