#include "stdafx.h"
#include <gtest/gtest.h>
#include "../numerical_analysis/na_algorithm.h"

using namespace na;

TEST(solveQuadraticEquation, test1)
{
	double x1, x2;
	EXPECT_TRUE( solveQuadraticEquation(1, -7, 12, x1, x2) );
	EXPECT_NEAR(4, x1, 0.0001);
	EXPECT_NEAR(3, x2, 0.0001);
}

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

TEST(solveLSEwithCMEGETest, solve3x3problem1)
{	
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init("8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2");
	EXPECT_DOUBLE_EQ(10.2, A[2][2]);
	b.init("6.1, 2.3, 1.8 ");
	EXPECT_DOUBLE_EQ(1.8, b[2]);
	EXPECT_TRUE(solveLSEwithCMEGE(A, x, b));
	EXPECT_NEAR(0.8409, x[0], 0.0005);
	EXPECT_NEAR(-0.2997, x[1], 0.0005);
	EXPECT_NEAR(0.01415, x[2], 0.0005);
}

TEST(solveLSEwithCMEGETest, solve3x3problem2)
{
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init("6 -12 6 -21 -3 24 -12 -12 51");
	EXPECT_DOUBLE_EQ(51, A[2][2]);
	b.init("-0.4082 -0.8981 -0.1633 ");
	EXPECT_DOUBLE_EQ(-0.1633, b[2]);
	EXPECT_TRUE(solveLSEwithCMEGE(A, x, b));
	EXPECT_NEAR(0.068, x[0], 0.0005);
	EXPECT_NEAR(0.0844, x[1], 0.0005);
	EXPECT_NEAR(0.0327, x[2], 0.0005);
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

TEST(solveLinearSimultaneousEquationsTest, solve4x4problemWithAllMethods)
{	
	Mat A(4, 4);
	Vec b(4);
	Vec x(4);
	A.init("8.3 2.1 -1.2 0.5 0.8 10.2 3.5 -1.8 1.2 0.2 -4 -0.5 -0.2 0.3 0.4 -2");
	b.init("-3.02 4.79 -6.72 8.89");
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION));
	EXPECT_NEAR(0.5, x[0], 0.005);
	EXPECT_NEAR(-1.1, x[1], 0.005);
	EXPECT_NEAR(2.3, x[2], 0.0005);
	EXPECT_NEAR(-4.2, x[3], 0.0005);

	x.zero();
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION));
	EXPECT_NEAR(0.5, x[0], 0.005);
	EXPECT_NEAR(-1.1, x[1], 0.005);
	EXPECT_NEAR(2.3, x[2], 0.0005);
	EXPECT_NEAR(-4.2, x[3], 0.0005);

	x.zero();
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_DOOLITTLE));
	EXPECT_NEAR(0.5, x[0], 0.005);
	EXPECT_NEAR(-1.1, x[1], 0.005);
	EXPECT_NEAR(2.3, x[2], 0.0005);
	EXPECT_NEAR(-4.2, x[3], 0.0005);

	x.zero();
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_MAJOR_ELEMENT_DOOLITTLE));
	EXPECT_NEAR(0.5, x[0], 0.005);
	EXPECT_NEAR(-1.1, x[1], 0.005);
	EXPECT_NEAR(2.3, x[2], 0.0005);
	EXPECT_NEAR(-4.2, x[3], 0.0005);

	x.zero();
	EXPECT_TRUE(solveLinearSimultaneousEquations(A, x, b, METHOD_JACOBI_ITERATION));
	EXPECT_NEAR(0.5, x[0], 0.005);
	EXPECT_NEAR(-1.1, x[1], 0.005);
	EXPECT_NEAR(2.3, x[2], 0.0005);
	EXPECT_NEAR(-4.2, x[3], 0.0005);
}

TEST(solveLSEwithDoolitlle, solve3x3problem)
{
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init("8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2");
	EXPECT_DOUBLE_EQ(10.2, A[2][2]);
	b.init("6.1, 2.3, 1.8 ");
	EXPECT_DOUBLE_EQ(1.8, b[2]);
	EXPECT_TRUE(solveLSEwithDoolittle(A, x, b));
	EXPECT_NEAR(0.8409, x[0], 0.0005);
	EXPECT_NEAR(-0.2997, x[1], 0.0005);
	EXPECT_NEAR(0.01415, x[2], 0.0005);
}

TEST(solveLSEwithMEDoolitlle, solve3x3problem)
{
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init("8.1, 2.3, -1.5, 0.5, -6.23, 0.87, 2.5, 1.5, 10.2");
	EXPECT_DOUBLE_EQ(10.2, A[2][2]);
	b.init("6.1, 2.3, 1.8 ");
	EXPECT_DOUBLE_EQ(1.8, b[2]);
	EXPECT_TRUE(solveLSEwithMEDoolittle(A, x, b));
	EXPECT_NEAR(0.8409, x[0], 0.0005);
	EXPECT_NEAR(-0.2997, x[1], 0.0005);
	EXPECT_NEAR(0.01415, x[2], 0.0005);
}

TEST(solveBandLinearSimultaneousEquations, 5x5problem1)
{
	Mat A(5, 5);
	Vec b(5);
	Vec x(5);
	A.init("4 1 0 0 0 1 4 1 0 0 0 1 4 1 0 0 0 1 4 1 0 0 0 1 4");
	b.init("1 0.5 -1 3 2");
	EXPECT_TRUE(solveBandLinearSimultaneousEquations(A, x, b, 1, 1));
	EXPECT_NEAR(0.2, x[0], 0.0005);
	EXPECT_NEAR(0.2, x[1], 0.0005);
	EXPECT_NEAR(-0.5, x[2], 0.0005);
	EXPECT_NEAR(0.8, x[3], 0.0005);
	EXPECT_NEAR(0.3, x[4], 0.0005);
}

TEST(solve3BLSEwithSpeedupMethod, 5x5problem1)
{
	Mat A(5, 5);
	Vec b(5);
	Vec x(5);
	A.init("4 1 0 0 0 1 4 1 0 0 0 1 4 1 0 0 0 1 4 1 0 0 0 1 4");
	b.init("1 0.5 -1 3 2");
	EXPECT_TRUE(solve3BLSEwithSpeedupMethod(A, x, b));
	EXPECT_NEAR(0.2, x[0], 0.0005);
	EXPECT_NEAR(0.2, x[1], 0.0005);
	EXPECT_NEAR(-0.5, x[2], 0.0005);
	EXPECT_NEAR(0.8, x[3], 0.0005);
	EXPECT_NEAR(0.3, x[4], 0.0005);
}

TEST(solveLSEwithJacobiIteration, 3x3problem)
{
	Mat A(3, 3);
	Vec b(3);
	Vec x(3);
	A.init("10 -2 -2 -2 10 -1 -1 -2 3");
	b.init("1 0.5 1");
	EXPECT_TRUE(solveLSEwithJacobiIteration(A, x, b));
	EXPECT_NEAR(0.231, x[0], 0.0005);
	EXPECT_NEAR(0.147, x[1], 0.0005);
	EXPECT_NEAR(0.508, x[2], 0.0005);
}