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

#include "io/Buffer.hpp"

namespace ng
{
  namespace io
  {
    Buffer::Buffer()
    {
      _data = nullptr;
      reset();
    }

    Buffer::~Buffer()
    {
      reset();
    }

    void Buffer::resize(std::size_t size)
    {
      reset();
      _data = new std::uint8_t[size];
      _size = size;
    }

    void Buffer::reset()
    {
      if (_data)
        delete[] _data;

      _data = nullptr;
      _pos = 0;
      _size = 0;
    }

    std::size_t Buffer::size() const
    {
      return (_size);
    }

    void Buffer::set(std::size_t pos, std::uint8_t value)
    {
      _data[pos] = value;
    }

    std::uint8_t Buffer::get(std::size_t pos) const
    {
      return (_data[pos]);
    }

    std::uint8_t Buffer::operator[](std::size_t pos) const
    {
      return (_data[pos]);
    }

    std::uint8_t *Buffer::getPtr() const
    {
      return (_data);
    }
  } /* namespace io */
} /* namespace ng */
