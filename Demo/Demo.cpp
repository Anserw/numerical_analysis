// Demo.cpp : Defines the entry point for the console application.
//

#include "../numerical_analysis/include/na_algorithm.h"
#include <iostream>

using namespace std;
using namespace na;

int main()
{
	double l_mat_A[9] = { 8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2 };
	double l_mat_b[3] = { 6.1, 2.3, 1.8 };
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init(l_mat_A);
	b.init(l_mat_b);
	solveLSEwithSGE(A, x, b);
	x.print();

	A.resize(5, 5);
	b.resize(5);
	x.resize(5);
	A.init("1 2 3 4 0 5 6 7 8 9 10 11 12 13 14 0 15 16 17 18 0 0 19 20 21");
	b.init("30 115 190 236 242");
	A.print();
	b.print();

	solveLSEwithMEDoolittle(A, x, b);
	//solveLSEwithCMEGE(A, x, b);
	//solveLSEwithDoolittle(A, x, b);
	//solveLSEwithSGE(A, x, b);
	x.print();

	
	//Mat C(4, 4);
	//C.init("2 1 0 6 3 2 0 0 2 3 5 1 -1 1 0 0");
	A.resize(4, 4);
	b.resize(4);
	x.resize(4);
	A.init("1 8 2 3 -6 -3 8 1 2 4 4 2 10 5 -5 6");
	b.init("12 40 -50 80");
	solveLSEwithMEDoolittle(A, x, b);
	x.print();

	A.init("8.3 2.1 -1.2 0.5 0.8 10.2 3.5 -1.8 1.2 0.2 -4 -0.5 -0.2 0.3 0.4 -2");
	b.init("-3.02 4.79 -6.72 8.89");
	solveLSEwithMEDoolittle(A, x, b);
	A.print();
	b.print();
	x.print();
	
	return 0;
}

