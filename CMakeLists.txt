cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(ng)

set(SRCS
    src/maths/AABB.cpp
    src/maths/Ray.cpp
    src/maths/Random.cpp
    src/maths/PerlinNoise.cpp
    src/utils/Logger.cpp
    src/system/Clock.cpp
    src/system/Duration.cpp
    src/graphics/impl/GLFW/GLFWKeyboard_mapping.cpp
    src/graphics/impl/GLFW/GLFWKeyboard.cpp
    src/graphics/impl/GLFW/GLFWMouse_mapping.cpp
    src/graphics/impl/GLFW/GLFWMouse.cpp
    src/graphics/impl/GLFW/GLFWWindow.cpp
    src/graphics/opengl/GLShader.cpp
    src/graphics/objects/Mesh.cpp
    src/graphics/Window.cpp
    src/io/formats/OBJFile.cpp
    src/io/Buffer.cpp
    src/io/File.cpp
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
# GLM
#
FetchContent_Declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
)
set(GLM_TEST_ENABLE OFF)

FetchContent_MakeAvailable(glm)

include_directories(${glm_SOURCE_DIR}/include)

#
# GLAD
#
add_subdirectory(deps/glad)


add_library(ng STATIC ${SRCS})

target_include_directories(ng PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ng glad glfw glm)
