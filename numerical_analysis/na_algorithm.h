#pragma once
#include "Mat.h"
#include "Vec.h"

using namespace na;

enum enum_method{
	//˳���˹��ȥ��
	METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION,

	//����Ԫ�ظ�˹��ȥ��
	METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION
};


bool solveLinearSimultaneousEquations(const Mat& A, Vec& x, const Vec& b, 
	enum_method method=METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION);

bool solveLSEwithSGE(const Mat& A, Vec& x, const Vec& b);

bool solveLSEwithCMEGE(const Mat& A, Vec& x, const Vec& b);