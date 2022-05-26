cmake_minimum_required(VERSION 3.21)
project(AoC2021_Day5)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(PROJECT_SOURCE
        src/main.cpp
        src/Grid.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE})

include(FindPkgConfig)
find_package(Functions REQUIRED)
include_directories(${FUNCTIONS_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${FUNCTIONS_LIBRARY})


