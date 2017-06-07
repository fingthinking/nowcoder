cmake_minimum_required(VERSION 3.7)
project(nowcoder)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        sword_to_offer/Solution_06.cpp sword_to_offer/Solution_07.cpp sword_to_offer/Solution_08.cpp sword_to_offer/Solution_09.cpp sword_to_offer/Solution_10.cpp sword_to_offer/Solution_11.cpp)

add_executable(nowcoder ${SOURCE_FILES})