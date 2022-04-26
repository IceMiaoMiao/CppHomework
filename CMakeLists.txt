cmake_minimum_required(VERSION 3.21)
project(CppHomework)

set(CMAKE_CXX_STANDARD 14)

add_executable(CppHomework main.cpp StudentManager.cpp StudentManager.h Student.cpp Student.h Common.cpp Common.h Header.cpp Header.h Master.cpp Master.h)
