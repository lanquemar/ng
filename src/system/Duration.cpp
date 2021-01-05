#include "system/Duration.hpp"

namespace ng
{
  namespace system
  {
    Duration::Duration()
    {
      _duration = std::chrono::seconds(0);
    }

    Duration::Duration(std::chrono::nanoseconds duration)
    {
      _duration = duration;
    }

    Duration::~Duration()
    {
    }

    std::int64_t Duration::asSeconds() const
    {
      return (std::chrono::duration_cast<std::chrono::seconds>(_duration).count());
    }

    std::int64_t Duration::asMilliseconds() const
    {

      return (std::chrono::duration_cast<std::chrono::milliseconds>(_duration).count());
    }

    std::int64_t Duration::asMicroseconds() const
    {
      return (std::chrono::duration_cast<std::chrono::microseconds>(_duration).count());
    }

    std::int64_t Duration::asNanoseconds() const
    {
      return (std::chrono::duration_cast<std::chrono::nanoseconds>(_duration).count());
    }

    Duration Duration::seconds(std::int64_t amount)
    {
      return (ng::system::Duration(std::chrono::seconds(amount)));
    }

    Duration Duration::milliseconds(std::int64_t amount)
    {
      return (ng::system::Duration(std::chrono::milliseconds(amount)));
    }

    Duration Duration::microseconds(std::int64_t amount)
    {
      return (ng::system::Duration(std::chrono::microseconds(amount)));
    }

    Duration Duration::nanoseconds(std::int64_t amount)
    {
      return (ng::system::Duration(std::chrono::nanoseconds(amount)));
    }

    void Duration::operator+=(ng::system::Duration const &obj)
    {
      _duration += obj.getHandle();
    }
    
    void Duration::operator-=(ng::system::Duration const &obj)
    {
      _duration -= obj.getHandle();
    }

    std::chrono::nanoseconds Duration::getHandle() const
    {
      return (_duration);
    }
  }
}


bool operator==(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (a.getHandle() == b.getHandle());
}

bool operator<=(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (a.getHandle() <= b.getHandle());
}

bool operator<(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (a.getHandle() < b.getHandle());
}

bool operator>=(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (a.getHandle() >= b.getHandle());
}

bool operator>(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (a.getHandle() > b.getHandle());
}

ng::system::Duration operator+(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (ng::system::Duration(a.getHandle() + b.getHandle()));
}

ng::system::Duration operator-(ng::system::Duration const &a, ng::system::Duration const &b)
{
  return (ng::system::Duration(a.getHandle() - b.getHandle()));
}
