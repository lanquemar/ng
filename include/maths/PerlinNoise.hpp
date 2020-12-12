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
        PerlinNoise(std::size_t w = 256);
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
  };
};
