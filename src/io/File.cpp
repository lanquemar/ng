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

#include <cerrno>
#include <cstring>

#include "io/File.hpp"
#include "exceptions/ErrorException.hpp"

namespace ng
{
  namespace io
  {
    File::File()
    {
      _opts = 0;
    }

    File::File(const std::string &filename) : _filename(filename)
    {
      _opts = 0;
    }

    File::~File()
    {
    }

    void File::open(int opts)
    {
      _opts = opts;
      _open(opts);
    }

    void File::open(const std::string &filename, int opts)
    {
      _opts = opts;
      _filename = filename;
      _open(opts);
    }

    std::size_t File::size()
    {
      if (!_file.is_open())
        return (-1);

      std::size_t save = _file.tellg();
      std::size_t size = _file.seekg(0, std::ios_base::end).tellg();

      _file.seekg(save, std::ios_base::beg);

      return (size);
    }

    void File::readAll(ng::io::Buffer &buffer)
    {
      if (!_file.is_open())
        throw ErrorException("Cannot read data without opening a file");

      std::size_t length = size();

      // In text mode, add NULL byte at the end
      buffer.resize(length + ((_opts & TEXT) ? 1 : 0));

      // TODO(Lanquemar): catch errors?
      // TODO(Lanquemar): check number of bytes read is
      // equal to length (especially in text mode)
      _file.read(reinterpret_cast<char *>(buffer.getPtr()), length);

      if (_opts & TEXT)
        buffer.set(length, 0);
    }

    void File::_open(int opts)
    {
      std::ios_base::openmode mode = (std::ios_base::openmode) 0;

      if (_file.is_open() || _filename.length() < 1)
        throw ErrorException("Bad filename or file already open");

      mode |= (_opts & READ) ? std::fstream::in :
        (std::ios_base::openmode) 0;
      mode |= (_opts & WRITE) ? std::fstream::out :
        (std::ios_base::openmode) 0;
      mode |= (_opts & BINARY) ? std::fstream::binary :
        (std::ios_base::openmode) 0;

      _file.open(_filename, mode);

      if (!_file.is_open())
        throw ErrorException(std::strerror(errno));
    }
  } /* namespace io */
} /* namespace ng */
