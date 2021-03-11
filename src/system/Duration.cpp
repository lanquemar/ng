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
      return (std::chrono::duration_cast<std::chrono::seconds>(
        _duration).count());
    }

    std::int64_t Duration::asMilliseconds() const
    {
      return (std::chrono::duration_cast<std::chrono::milliseconds>(
        _duration).count());
    }

    std::int64_t Duration::asMicroseconds() const
    {
      return (std::chrono::duration_cast<std::chrono::microseconds>(
        _duration).count());
    }

    std::int64_t Duration::asNanoseconds() const
    {
      return (std::chrono::duration_cast<std::chrono::nanoseconds>(
        _duration).count());
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
  } /* namespace system */
} /* namespace ng */


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

ng::system::Duration operator+(ng::system::Duration const &a,
  ng::system::Duration const &b)
{
  return (ng::system::Duration(a.getHandle() + b.getHandle()));
}

ng::system::Duration operator-(ng::system::Duration const &a,
  ng::system::Duration const &b)
{
  return (ng::system::Duration(a.getHandle() - b.getHandle()));
}
