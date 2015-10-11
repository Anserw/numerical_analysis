#pragma once
#include "Mat.h"

using namespace na;

enum enum_method{
	METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION
};


bool solveLinearSimultaneousEquations(const Mat& A, Mat& x, const Mat& b, 
	enum_method method=METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION);

bool solveLSEwithSGE(const Mat& A, Mat& x, const Mat& b);