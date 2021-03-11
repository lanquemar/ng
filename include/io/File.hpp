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

#include <string>
#include <fstream>

#include "Buffer.hpp"

namespace ng
{
  namespace io
  {
    class File
    {
      public:
        enum mode
        {
          READ = 1 << 0,
          WRITE = 1 << 1,
          TEXT = 1 << 2,
          BINARY = 1 << 3
        };

        File();
        explicit File(const std::string &);
        ~File();

        void open(int opts = READ | BINARY);
        void open(const std::string &, int opts = READ | BINARY);
        std::size_t size();
        void readAll(ng::io::Buffer &);

      private:
        void _open(int);

        std::string _filename;
        int _opts;
        std::fstream _file;
    };
  }; /* namespace io */
}; /* namespace ng */
