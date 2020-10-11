#pragma once

#include <exception>

namespace ng
{
  class ErrorException : public std::exception
  {
    public:
      ErrorException(char const * const msg) throw() : _msg(msg) {}
      virtual char const* what() const throw()
      {
        return (_msg);
      }

    private:
      char const * const _msg;
  };
};