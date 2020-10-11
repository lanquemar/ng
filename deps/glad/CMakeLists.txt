cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(glad)

set(SRCS
    src/glad.c
)

add_library(glad STATIC ${SRCS})

target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)