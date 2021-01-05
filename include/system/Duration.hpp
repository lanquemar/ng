#pragma once

#include <chrono>
#include <cstdint>

namespace ng
{
  namespace system
  {
    class Duration
    {
      public:
        Duration();
        Duration(std::chrono::nanoseconds);
        ~Duration();

        std::int64_t asSeconds() const;
        std::int64_t asMilliseconds() const;
        std::int64_t asMicroseconds() const;
        std::int64_t asNanoseconds() const;

        static Duration seconds(std::int64_t);
        static Duration milliseconds(std::int64_t);
        static Duration microseconds(std::int64_t);
        static Duration nanoseconds(std::int64_t);

        void operator+=(ng::system::Duration const&);
        void operator-=(ng::system::Duration const&);

        std::chrono::nanoseconds getHandle() const;

      private:
        std::chrono::nanoseconds _duration;
    };
  };
};

/*
** OPERATORS
*/

bool operator==(ng::system::Duration const&, ng::system::Duration const&);
bool operator<=(ng::system::Duration const&, ng::system::Duration const&);
bool operator<(ng::system::Duration const&, ng::system::Duration const&);
bool operator>=(ng::system::Duration const&, ng::system::Duration const&);
bool operator>(ng::system::Duration const&, ng::system::Duration const&);

ng::system::Duration operator+(ng::system::Duration const&, ng::system::Duration const&);
ng::system::Duration operator-(ng::system::Duration const&, ng::system::Duration const&);
