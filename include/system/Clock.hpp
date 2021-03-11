#pragma once

#include <chrono>

#include "Duration.hpp"

namespace ng
{
  namespace system
  {
    class Clock
    {
      public:
        Clock();
        ~Clock();

        ng::system::Duration getTime() const;
        void restart();

      private:
        std::chrono::high_resolution_clock::time_point _start;
    };
  };
};