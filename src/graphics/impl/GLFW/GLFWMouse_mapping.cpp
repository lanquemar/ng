// MIT License
//
// Copyright (c) 2021 Adrien Vasseur
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstddef>

#include "GLFWMouse.hpp"

#include "graphics/Mouse.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      const std::size_t GLFWMouse::glfwToNgSize =
        GLFW_MOUSE_BUTTON_8 + 1;
      const ng::graphics::Mouse::Key GLFWMouse::glfwToNg[glfwToNgSize] = {
        ng::graphics::Mouse::BUTTON_1, // 0 GLFW_MOUSE_BUTTON_1
        ng::graphics::Mouse::BUTTON_2, // 1 GLFW_MOUSE_BUTTON_2
        ng::graphics::Mouse::BUTTON_3, // 2 GLFW_MOUSE_BUTTON_3
        ng::graphics::Mouse::BUTTON_4, // 3 GLFW_MOUSE_BUTTON_4
        ng::graphics::Mouse::BUTTON_5, // 4 GLFW_MOUSE_BUTTON_5
        ng::graphics::Mouse::BUTTON_6, // 5 GLFW_MOUSE_BUTTON_6
        ng::graphics::Mouse::BUTTON_7, // 6 GLFW_MOUSE_BUTTON_7
        ng::graphics::Mouse::BUTTON_8  // 7 GLFW_MOUSE_BUTTON_8
      };

      const std::size_t GLFWMouse::ngToGlfwSize =
        ng::graphics::Mouse::BUTTON_9 + 1;
      const int GLFWMouse::ngToGlfw[ngToGlfwSize] = {
        GLFW_MOUSE_BUTTON_1, // 0 ng::graphics::Mouse::BUTTON_1
        GLFW_MOUSE_BUTTON_2, // 1 ng::graphics::Mouse::BUTTON_2
        GLFW_MOUSE_BUTTON_3, // 2 ng::graphics::Mouse::BUTTON_3
        GLFW_MOUSE_BUTTON_4, // 3 ng::graphics::Mouse::BUTTON_4
        GLFW_MOUSE_BUTTON_5, // 4 ng::graphics::Mouse::BUTTON_5
        GLFW_MOUSE_BUTTON_6, // 5 ng::graphics::Mouse::BUTTON_6
        GLFW_MOUSE_BUTTON_7, // 6 ng::graphics::Mouse::BUTTON_7
        GLFW_MOUSE_BUTTON_8, // 7 ng::graphics::Mouse::BUTTON_8
        GLFW_KEY_UNKNOWN,    // 8 ng::graphics::Mouse::BUTTON_9
      };
    } /* namespace impl */
  } /* namespace graphics */
} /* namespace ng */
