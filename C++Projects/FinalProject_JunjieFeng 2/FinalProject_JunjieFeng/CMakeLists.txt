cmake_minimum_required(VERSION 3.3)
project(FinalProject_JunjieFeng)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    FinalProject/Account_JunjieFeng.h
    FinalProject/BankAccount_JunjieFeng.cpp
    FinalProject/BankAccount_JunjieFeng.h
    FinalProject/Main_JunjieFeng.cpp
    FinalProject/StockAccount_JunjieFeng.cpp
    FinalProject/StockAccount_JunjieFeng.h
    FinalProject/StockNode_JunjieFeng.cpp
    FinalProject/StockNode_JunjieFeng.h)

add_executable(FinalProject_JunjieFeng ${SOURCE_FILES})