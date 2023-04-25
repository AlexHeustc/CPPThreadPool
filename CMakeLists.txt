cmake_minimum_required(VERSION 3.23)
project(CPPThreadPool)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(CPPThreadPool Src/main.cpp Src/TaskQueue.cpp Headers/TaskQueue.h Src/ThreadPool.cpp Headers/ThreadPool.h)
