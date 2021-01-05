#include "system/Clock.hpp"

namespace ng
{
  namespace system
  {
    Clock::Clock()
    {
      restart();
    }

    Clock::~Clock()
    {
      
    }

    ng::system::Duration Clock::getTime() const
    {
      return (ng::system::Duration(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - _start)));
    }

    void Clock::restart()
    {
      _start = std::chrono::high_resolution_clock::now();
    }
  }
}
