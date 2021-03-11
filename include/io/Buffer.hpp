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
#include <cstddef>

namespace ng
{
  namespace io
  {
    class Buffer
    {
      public:
        Buffer();
        ~Buffer();

        void resize(std::size_t);
        void reset();
        std::size_t size() const;

        void set(std::size_t, std::uint8_t);
        std::uint8_t get(std::size_t) const;
        std::uint8_t operator[](std::size_t) const;

        std::uint8_t *getPtr() const;

      private:
        std::uint8_t *_data;
        std::size_t _pos;
        std::size_t _size;
    };
  }; /* namespace io */
}; /* namespace ng */
