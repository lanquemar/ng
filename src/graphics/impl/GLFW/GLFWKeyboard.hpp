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

#pragma once

#include <GLFW/glfw3.h>
#include <cstddef>

#include "graphics/Keyboard.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWWindow;

      class GLFWKeyboard : public ng::graphics::Keyboard
      {
        public:
          explicit GLFWKeyboard(GLFWWindow *);
          ~GLFWKeyboard();

          bool isKeyPressed(ng::graphics::Keyboard::Key) override;

          static const std::size_t glfwToNgSize;
          static const ng::graphics::Keyboard::Key glfwToNg[];

          static const std::size_t ngToGlfwSize;
          static const int ngToGlfw[];

        private:
          ::GLFWwindow *_window;
      };
    }; /* namespace impl */
  }; /* namespace graphics */
}; /* namespace ng */
