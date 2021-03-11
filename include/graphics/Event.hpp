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

#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace ng
{
  namespace graphics
  {
    class Event
    {
      public:
        enum Type
        {
          NONE,
          CLOSED,
          RESIZED,
          KEY_PRESSED,
          KEY_RELEASED,
          MOUSE_PRESSED,
          MOUSE_RELEASED,
          MOUSE_MOVED,
          MOUSE_ENTERED,
          MOUSE_LEFT,
          MOUSE_SCROLL
        };

        Type type;

        struct SizeInfo
        {
          std::uint32_t width;
          std::uint32_t height;
        };

        struct PositionInfo
        {
          std::uint32_t x;
          std::uint32_t y;
        };

        struct DeltaInfo
        {
          std::int32_t x;
          std::int32_t y;
        };

        struct KeyInfo
        {
          Keyboard::Key key;
          bool alt;
          bool control;
          bool shift;
          bool system;
          bool capslock;
          bool numlock;
        };

        struct ButtonInfo
        {
          Mouse::Key key;
          bool alt;
          bool control;
          bool shift;
          bool system;
          bool capslock;
          bool numlock;
        };

        union
        {
          KeyInfo key;
          ButtonInfo button;
          SizeInfo size;
          PositionInfo pos;
          DeltaInfo delta;
        };
    };
  }; /* namespace graphics */
}; /* namespace ng */
