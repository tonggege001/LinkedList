cmake_minimum_required(VERSION 3.6)
project(LinkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LinkedList.cpp LinkedList.h)
add_executable(LinkedList ${SOURCE_FILES} LinkedList.cpp LinkedList.h)