cmake_minimum_required(VERSION 3.21)
project(proj_20_AED_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj_20_AED_main
        classesClass.cpp
        classesClass.h
        classesPerUC.h
        classesPerUcClass.cpp
        classesPerUcClass.h
        classesStruct.h
        main.cpp
        studentsClassesClass.cpp
        studentsClassesClass.h
        StudentsClassesStruct.h)
