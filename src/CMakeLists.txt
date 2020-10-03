PROJECT(leetcode)

SET(SRC_LIST hello.cpp foo.cpp topKFrequent.cpp videoStitching1024.cpp UndergroundSystem.cpp canVisitAllRooms841.cpp longestCommonSubsequence.cpp minDistance583.cpp countSubstrings647.cpp numMovesStonesII1040.cpp)

include_directories(${PROJECT_SOURCE_DIR}/../include)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_LIST})