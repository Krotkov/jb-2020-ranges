cmake_minimum_required(VERSION 3.15)
project(jb_2020_ranges)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)

add_executable(minDistance main.cpp)
target_link_libraries(minDistance minDistanceLib)

add_executable(test testing.cpp)
target_link_libraries(test minDistanceLib)
