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
  };
};