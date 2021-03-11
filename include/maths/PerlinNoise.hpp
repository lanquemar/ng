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

#pragma once

#include <cstddef>
#include <cstdint>

#include "Random.hpp"

/*
** This is a basic implementation of the improved Perlin noise algorithm.
**
** Inspired from the original Java reference implementation made by Ken Perlin
** (https://cs.nyu.edu/~perlin/noise/).
**
** This is *not* a fast implementation.
*/

namespace ng
{
  namespace maths
  {
    class PerlinNoise
    {
      public:
        explicit PerlinNoise(std::size_t w = 256);
        ~PerlinNoise();

        double get(double) const;
        double get(double, double) const;
        double get(double, double, double) const;

        double fractal(std::size_t, double) const;
        double fractal(std::size_t, double, double) const;
        double fractal(std::size_t, double, double, double) const;

      private:
        double _fade(double) const;
        double _lerp(double, double, double) const;
        double _grad(std::uint32_t, double, double, double) const;
        void _generatePermutationTable();

        Random _rand;
        std::uint32_t *_permutationTable;
        std::size_t _permutationTableSize;
    };
  }; /* namespace maths */
}; /* namespace ng */
