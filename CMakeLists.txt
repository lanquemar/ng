cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(ng)

set(SRCS
    src/utils/Logger.cpp
    src/graphics/impl/GLFW/GLFWWindow.cpp
    src/graphics/Window.cpp
    src/Sample.cpp
)

include(FetchContent)

#
# GLFW
#
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.2
)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)

FetchContent_MakeAvailable(glfw)

include_directories(${glfw_SOURCE_DIR}/include)


#
# GLAD
#
add_subdirectory(deps/glad)


add_library(ng STATIC ${SRCS})

target_include_directories(ng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ng glad glfw)