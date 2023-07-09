cmake_minimum_required(VERSION 3.23)
project(Section6)

set(CMAKE_CXX_STANDARD 20)

add_executable(MergeSort Sorting/MergeSort.cpp)
add_executable(InversionCount Sorting/InversionCount.cpp)
add_executable(Quicksort Sorting/Quicksort.cpp)
add_executable(SelectQuick Sorting/SelectQuick.cpp)
add_executable(SmallestString Sorting/SmallestString.cpp)
add_executable(SpareSearch Sorting/SpareSearch.cpp)
add_executable(Exercises Sorting/Exercises.cpp)
add_executable(Challenge Challenge/Challenges.cpp)