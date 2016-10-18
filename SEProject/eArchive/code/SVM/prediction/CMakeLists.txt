cmake_minimum_required(VERSION 3.3)
project(prediction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    TestingData_Weight.txt)

add_executable(prediction ${SOURCE_FILES})