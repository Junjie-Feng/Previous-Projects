cmake_minimum_required(VERSION 3.3)
project(Homework_9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Display_JunjieFeng.cpp
    Main_JunjieFeng.cpp
    OvernightPackage_JunjieFeng.cpp
    OvernightPackage_JunjieFeng.h
    Package_JunjieFeng.cpp
    Package_JunjieFeng.h
    TwoDayPackage_JunjieFeng.cpp
    TwoDayPackage_JunjieFeng.h)

add_executable(Homework_9 ${SOURCE_FILES})