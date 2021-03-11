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

#include <cstdint>

#include "Event.hpp"

namespace ng
{
  namespace graphics
  {
    class Window
    {
      public:
        virtual ~Window() {}

        virtual void open(const std::int32_t = 800,
          const std::int32_t = 600) = 0;
        virtual void close() = 0;
        virtual bool isOpen() = 0;

        virtual void draw() = 0;
        virtual void pollEvents(ng::graphics::Event &) = 0;

        virtual std::int32_t getWidth() const = 0;
        virtual std::int32_t getHeight() const = 0;

        virtual ng::graphics::Keyboard *getKeyboard() = 0;
        virtual ng::graphics::Mouse *getMouse() = 0;

        static Window* create();
    };
  }; /* namespace graphics */
}; /* namespace ng */
