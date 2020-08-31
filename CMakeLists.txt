cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(ng)

set(SRCS
    src/Sample.cpp
)

add_library(ng STATIC ${SRCS})

target_include_directories(ng PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/src)
target_link_libraries(ng)