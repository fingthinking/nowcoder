cmake_minimum_required(VERSION 3.7)
project(nowcoder)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        sword_to_offer/Solution_23.cpp sword_to_offer/Solution_24.cpp)

add_executable(nowcoder ${SOURCE_FILES})