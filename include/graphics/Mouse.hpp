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

#include <glm/gtc/type_ptr.hpp>

namespace ng
{
  namespace graphics
  {
    class Mouse
    {
      public:
        // See further down for declaration
        enum Key: int;

        virtual ~Mouse() {}

        virtual bool isButtonPressed(ng::graphics::Mouse::Key) const = 0;
        virtual glm::ivec2 getPosition() const = 0;

        enum Key: int
        {
          UNKNOWN = -1,
          BUTTON_1 = 0,
          BUTTON_2,
          BUTTON_3,
          BUTTON_4,
          BUTTON_5,
          BUTTON_6,
          BUTTON_7,
          BUTTON_8,
          BUTTON_9
        };
    };
  }; /* namespace graphics */
}; /* namespace ng */
