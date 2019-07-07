cmake_minimum_required(VERSION 3.13)
project(MultithreadExmaples)

set(CMAKE_CXX_STANDARD 14)
find_package (Threads)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(VolatileOptimize volatile-optimize.cpp)

TARGET_LINK_LIBRARIES( VolatileOptimize  pthread )
