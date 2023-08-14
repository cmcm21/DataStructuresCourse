cmake_minimum_required(VERSION 3.23)
project(Section7Searching)

set(CMAKE_CXX_STANDARD 14)
add_executable(Section7Searching main.cpp BinarySearch/BinarySearchUtilities.cpp)
add_executable(GreedyGame Problems/GreedyGame.cpp BinarySearch/BinarySearchUtilities.cpp)
