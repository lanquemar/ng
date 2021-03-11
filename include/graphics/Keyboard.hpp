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

namespace ng
{
  namespace graphics
  {
    class Keyboard
    {
      public:
        // See further down for declaration
        enum Key: int;

        virtual ~Keyboard() {}

        virtual bool isKeyPressed(ng::graphics::Keyboard::Key) = 0;

        enum Key: int
        {
          UNKNOWN = -1,
          A = 0,
          B,
          C,
          D,
          E,
          F,
          G,
          H,
          I,
          J,
          K,
          L,
          M,
          N,
          O,
          P,
          Q,
          R,
          S,
          T,
          U,
          V,
          W,
          X,
          Y,
          Z,
          NUM_0,
          NUM_1,
          NUM_2,
          NUM_3,
          NUM_4,
          NUM_5,
          NUM_6,
          NUM_7,
          NUM_8,
          NUM_9,
          ESCAPE,
          SPACE,
          APOSTROPHE,
          COMMA,
          MINUS,
          PERIOD,
          SLASH,
          SEMICOLON,
          EQUAL,
          LEFT_BRACKET,
          BACKSLASH,
          RIGHT_BRACKET,
          GRAVE_ACCENT,
          ENTER,
          TAB,
          BACKSPACE,
          INSERT,
          DELETE,
          RIGHT,
          LEFT,
          DOWN,
          UP,
          PAGE_UP,
          PAGE_DOWN,
          HOME,
          END,
          CAPS_LOCK,
          SCROLL_LOCK,
          NUM_LOCK,
          PRINT_SCREEN,
          PAUSE,
          F1,
          F2,
          F3,
          F4,
          F5,
          F6,
          F7,
          F8,
          F9,
          F10,
          F11,
          F12,
          F13,
          F14,
          F15,
          F16,
          F17,
          F18,
          F19,
          F20,
          F21,
          F22,
          F23,
          F24,
          F25,
          NUMPAD_0,
          NUMPAD_1,
          NUMPAD_2,
          NUMPAD_3,
          NUMPAD_4,
          NUMPAD_5,
          NUMPAD_6,
          NUMPAD_7,
          NUMPAD_8,
          NUMPAD_9,
          DECIMAL,
          DIVIDE,
          MULTIPLY,
          SUBSTRACT,
          ADD,
          LEFT_SHIFT,
          LEFT_CONTROL,
          LEFT_ALT,
          LEFT_SYSTEM,
          RIGHT_SHIFT,
          RIGHT_CONTROL,
          RIGHT_ALT,
          RIGHT_SYSTEM,
          MENU
        };
    };
  }; /* namespace graphics */
}; /* namespace ng */
