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

#include <cstdint>

#include "graphics/Window.hpp"
#include "GLFWKeyboard.hpp"
#include "GLFWMouse.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWWindow : public Window
      {
        public:
          GLFWWindow();
          ~GLFWWindow();

          void open(const std::int32_t = 800,
            const std::int32_t = 600) override;
          void close() override;
          bool isOpen() override;

          void draw() override;
          void pollEvents(ng::graphics::Event &) override;

          std::int32_t getWidth() const override;
          std::int32_t getHeight() const override;

          ng::graphics::Keyboard *getKeyboard() override;
          ng::graphics::Mouse *getMouse() override;

          void onKey(int, int, int, int);
          void onText(unsigned int);
          void onResize(int, int);
          void onMouseMove(double, double);
          void onMouseEnter(int);
          void onMouseButton(int, int, int);
          void onMouseScroll(double, double);

          ::GLFWwindow *getHandle() const;

        private:
          void _throwGLFWError();

          ::GLFWwindow *_window;
          bool _initialized;
          std::int32_t _width;
          std::int32_t _height;

          ng::graphics::impl::GLFWKeyboard *_keyboard;
          ng::graphics::impl::GLFWMouse *_mouse;

          ng::graphics::Event *_event;
      };
    }; /* namespace impl */
  }; /* namespace graphics */
}; /* namespace ng */
