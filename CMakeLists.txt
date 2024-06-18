cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(algoflow)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion")

add_subdirectory(graph/cpp)
add_subdirectory(upsolve/)
