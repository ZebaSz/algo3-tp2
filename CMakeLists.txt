cmake_minimum_required(VERSION 2.6)
project(algo3_tp2)

set(SOURCE_FILES
        src/shortest.cpp src/graph.h
        src/Utils.cpp src/subsidy.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_library(algo3-tp2-base ${SOURCE_FILES})

add_executable(problema1 src/problema1.cpp)
target_link_libraries (problema1 algo3-tp2-base)
add_executable(problema2 src/problema2.cpp)
target_link_libraries (problema2 algo3-tp2-base)
add_executable(problema3 src/problema3.cpp)
target_link_libraries (problema3 algo3-tp2-base)

add_subdirectory(test)

#add_subdirectory(data)
