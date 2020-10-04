PROJECT(leetcode)

#将当前文件目录下所有的源文件名称赋值给参数SRC_LIST
AUX_SOURCE_DIRECTORY(. SRC_LIST)

# SET(SRC_LIST hello.cpp foo.cpp topKFrequent.cpp videoStitching1024.cpp UndergroundSystem.cpp canVisitAllRooms841.cpp longestCommonSubsequence.cpp minDistance583.cpp countSubstrings647.cpp numMovesStonesII1040.cpp)

include_directories(${PROJECT_SOURCE_DIR}/../include)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_LIST})