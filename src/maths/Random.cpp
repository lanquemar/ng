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

#include "maths/Random.hpp"

#include <cstdlib>
#include <ctime>

namespace ng
{
  namespace maths
  {
    Random::Random()
    {
      reset();
      // Avoid getting the first number to increase entropy
      // (on Windows, first numbers are sometimes pretty close
      // when seed is close)
      nextInt();
    }

    Random::~Random()
    {
    }

    int Random::nextInt()
    {
      return (std::rand());
    }

    int Random::nextInt(int max)
    {
      return (std::rand() % max);
    }

    int Random::nextInt(int min, int max)
    {
      return (min + std::rand() % max);
    }

    float Random::nextUnit()
    {
      return (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX));
    }

    void Random::reset()
    {
      std::srand((unsigned) time(0));
    }
  } /* namespace maths */
} /* namespace ng */
