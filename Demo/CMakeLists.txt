PROJECT(numerical_analysis)
cmake_minimum_required(VERSION 2.8)


INCLUDE_DIRECTORIES(
	include
)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)

SET(numerical_analysis
	${DIR_SRCS}
)

SET(LIBRARIES
	m
)

ADD_LIBRARY(numerical_analysis ${DIR_SRCS})

#ADD_EXECUTABLE( ${})

TARGET_LINK_LIBRARIES(numerical_analysis ${LIBRARIES})
