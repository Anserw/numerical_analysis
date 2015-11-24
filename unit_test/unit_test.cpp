// unit_test.cpp : Defines the entry point for the console application.
//

#include <gtest/gtest.h>


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();		
	return 0;
}

