#include "io/File.hpp"

#include <exception>
#include <iostream>

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
      // TODO: replace by a real exception with a what
      if (!_file.is_open())
        throw new std::exception;

      std::size_t length = size();

      // In text mode, add NULL byte at the end
      buffer.resize(length + ((_opts & TEXT) ? 1 : 0));

      // TODO: catch errors?
      // TODO: check number of bytes read is equal to length (especially in text mode)
      _file.read((char *)(buffer.getPtr()), length);

      if (_opts & TEXT)
        buffer.set(length, 0);
    }

    void File::_open(int opts)
    {
      std::ios_base::openmode mode = (std::ios_base::openmode) 0;

      // TODO: replace by a real exception with a what
      if (_file.is_open() || _filename.length() < 1)
        throw new std::exception;

      mode |= (_opts & READ) ? std::fstream::in : (std::ios_base::openmode) 0;
      mode |= (_opts & WRITE) ? std::fstream::out : (std::ios_base::openmode) 0;
      mode |= (_opts & BINARY) ? std::fstream::binary : (std::ios_base::openmode) 0;

      _file.open(_filename, mode);

      // TODO: throws right exception with right error message
      if (!_file.is_open())
        throw new std::exception;
    }
  }
}