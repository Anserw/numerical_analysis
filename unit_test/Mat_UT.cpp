#include "stdafx.h"
#include <gtest/gtest.h>
#include "../numerical_analysis/Mat.h"
#include "../numerical_analysis/Vec.h"

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

TEST(VecTest, operatorBrace)
{
	double l_vec[3] = { 1, 2, 3 };
	Vec a(3);
	a.init(l_vec);
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);

}