#include "stdafx.h"
#include <gtest/gtest.h>
#include "../numerical_analysis/na_algorithm.h"


TEST(solveLSEwithSGETest, solve3x3problem1)
{
	double l_mat_A[9] = { 8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2 };
	double l_mat_b[3] = { 6.1, 2.3, 1.8 };
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init(l_mat_A);
	b.init(l_mat_b);
	EXPECT_TRUE(solveLSEwithSGE(A, x, b));
	EXPECT_NEAR(0.8409, x[0], 0.0005);
	EXPECT_NEAR(-0.2997, x[1], 0.0005);
	EXPECT_NEAR(0.01415, x[2], 0.0005);	
}

TEST(solveLSEwithSGETest, solve3x3problem2)
{
	double l_mat_A[9] = { 0.012, 0.01, 0.167, 1, 0.8334, 5.91, 3200, 1200, 4.2 };
	double l_mat_b[3] = { 0.6781, 12.1, 981 };
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init(l_mat_A);
	b.init(l_mat_b);
	EXPECT_TRUE(solveLSEwithSGE(A, x, b));
	EXPECT_NEAR(17.46, x[0], 0.005);
	EXPECT_NEAR(-45.76, x[1], 0.005);
	EXPECT_NEAR(5.546, x[2], 0.0005);
}

TEST(solveLinearSimultaneousEquationsTest, solve3x3problemWithSequentialGaussianElimination)
{
	double l_mat_A[9] = { 0.012, 0.01, 0.167, 1, 0.8334, 5.91, 3200, 1200, 4.2 };
	double l_mat_b[3] = { 0.6781, 12.1, 981 };
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init(l_mat_A);
	b.init(l_mat_b);
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION));
	EXPECT_NEAR(17.46, x[0], 0.005);
	EXPECT_NEAR(-45.76, x[1], 0.005);
	EXPECT_NEAR(5.546, x[2], 0.0005);
}