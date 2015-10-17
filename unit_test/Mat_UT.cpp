#include "stdafx.h"
#include <gtest/gtest.h>
#include "../numerical_analysis/Mat.h"
#include "../numerical_analysis/Vec.h"
#include "math.h"

using namespace na;

TEST(MatTest, operatorBrace)
{
	double l_mat_A[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	Mat A(3, 3);
	A.init(l_mat_A);
	EXPECT_EQ(0, A[0][0]);
	EXPECT_EQ(1, A[0][1]);
	EXPECT_EQ(2, A[0][2]);
	EXPECT_EQ(3, A[1][0]);
	EXPECT_EQ(4, A[1][1]);
	EXPECT_EQ(5, A[1][2]);
	EXPECT_EQ(6, A[2][0]);
	EXPECT_EQ(7, A[2][1]);
}

TEST(MatTest, func_input)
{
	Mat A(3, 3);
	EXPECT_TRUE( A.init("1, 2.2, 3.0, 0.1, 123") );
	EXPECT_DOUBLE_EQ(1, A[0][0]);
	EXPECT_DOUBLE_EQ(2.2, A[0][1]);
	EXPECT_DOUBLE_EQ(3.0, A[0][2]);
	EXPECT_DOUBLE_EQ(0.1, A[1][0]);
	EXPECT_DOUBLE_EQ(123, A[1][1]);
	
}

TEST(MatTest, func_norm)
{
	Mat a(3, 3);
	EXPECT_TRUE(a.init("2 -5 4 -1 0 3 4 2 -2"));
	EXPECT_DOUBLE_EQ(9, a.norm1());
	EXPECT_DOUBLE_EQ(11, a.normi());
	EXPECT_DOUBLE_EQ(sqrt(79), a.normF());
}

TEST(VecTest, operatorBrace)
{
	double l_vec[3] = { 1, 2, 3 };
	Vec a(3);
	a.init(l_vec);
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);

}

TEST(VecTest, func_norm)
{
	Vec x(3);
	x.init("4 -8 2");
	EXPECT_DOUBLE_EQ(14, x.norm1());
	EXPECT_DOUBLE_EQ(2 * sqrt(21), x.norm2());
	EXPECT_DOUBLE_EQ(8, x.normi());
}