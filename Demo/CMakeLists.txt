PROJECT(numerical_analysis_demo)
cmake_minimum_required(VERSION 2.8)

SET(LIB_NUMERICAL_ANALYSIS_PATH
	../../numerical_analysis/lib
)

SET(EXECUTABLE_OUTPUT_PATH
	../bin
)

INCLUDE_DIRECTORIES(
	../numerical_analysis/include
)

LINK_DIRECTORIES(
	${LIB_NUMERICAL_ANALYSIS_PATH}
)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

SET(numerical_analysis_demo
	${DIR_SRCS}
)

SET(LIBRARIES
	m
	numerical_analysis
)

#ADD_LIBRARY(numerical_analysis ${DIR_SRCS})

ADD_EXECUTABLE(numerical_analysis_demo ${DIR_SRCS})

TARGET_LINK_LIBRARIES(numerical_analysis_demo ${LIBRARIES})
