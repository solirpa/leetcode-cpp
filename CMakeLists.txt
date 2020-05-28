cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode_cpp main.cpp)

add_executable(two_sum ./leetcode/editor/cn/1.two_sum.cpp)
add_executable(3sum ./leetcode/editor/cn/15.3sum.cpp)