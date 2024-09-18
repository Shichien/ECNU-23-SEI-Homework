cmake_minimum_required(VERSION 3.25)
project(Airport)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Airport
        Main.cpp
        MyQueue.cpp
        MyQueue.h
        Plane.cpp
        Plane.h
        Random.cpp
        Random.h
        Runway.cpp
        Runway.h Plane.cpp)
