cmake_minimum_required(VERSION 3.31)
project(vector_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(vector_class main.cpp
        MyVector.h
        Subscriber.h
        Subscriber.cpp)
