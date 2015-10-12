#pragma once
#include "Mat.h"
#include "Vec.h"

using namespace na;

enum enum_method{
	METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION
};


bool solveLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b, 
	enum_method method=METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION);

bool solveLSEwithSGE(const Mat& A, Vec& x, const Vec& b);