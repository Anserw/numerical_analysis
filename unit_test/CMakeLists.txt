PROJECT(numerical_analysis_UT)
cmake_minimum_required(VERSION 2.8)

SET(LIB_GOOGLETEST_PATH
	~/git/googletest/googletest/lib
)

SET(INCLUDE_GOOGLETEST_PATH
	~/git/googletest/googletest/include
)

SET(LIB_NUMERICAL_ANALYSIS_PATH
	../../numerical_analysis/lib
)

SET(EXECUTABLE_OUTPUT_PATH
	../bin
)

INCLUDE_DIRECTORIES(
	../numerical_analysis/include
	${INCLUDE_GOOGLETEST_PATH}
)

LINK_DIRECTORIES(
	${LIB_NUMERICAL_ANALYSIS_PATH}
	${LIB_GOOGLETEST_PATH}
)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

SET(numerical_analysis_UT
	${DIR_SRCS}
)

SET(LIBRARIES
	m
	numerical_analysis
	gtest
	gtest_main
	pthread
)

#ADD_LIBRARY(numerical_analysis ${DIR_SRCS})

ADD_EXECUTABLE(numerical_analysis_UT ${DIR_SRCS})

TARGET_LINK_LIBRARIES(numerical_analysis_UT ${LIBRARIES})
