cmake_minimum_required(VERSION 3.13)

SET(PROJECT_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_PATH}/bin)
add_compile_options(-g)
add_compile_options(-std=c++11)

add_subdirectory(src)


PROJECT(main)
SET(SRC_LIST main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

ADD_EXECUTABLE(main ${SRC_LIST})

TARGET_LINK_LIBRARIES(main leetcode)
link_directories(${PROJECT_SOURCE_DIR}/src)
