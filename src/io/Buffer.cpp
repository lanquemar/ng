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
  }
}