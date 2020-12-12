#include "maths/PerlinNoise.hpp"

#include <cmath>

namespace ng
{
  namespace maths
  {
    /*
    ** Create a Perlin noise generator composed of a permutation table of size w
    ** meaning the noise get repeated every w
    */
    PerlinNoise::PerlinNoise(std::size_t w)
    {
      _permutationTable = nullptr;
      _permutationTableSize = w;

      _generatePermutationTable();
    }

    PerlinNoise::~PerlinNoise()
    {
      if (_permutationTable)
        delete [] _permutationTable;
    }

    /*
    ** Returns Perlin noise value for (x) point
    ** in range [-1.0, 1.0f].
    */
    double PerlinNoise::get(double x) const
    {
      return (get(x, 0, 0));
    }

    /*
    ** Returns Perlin noise value for (x, y) point
    ** in range [-1.0, 1.0f].
    */
    double PerlinNoise::get(double x, double y) const
    {
      return (get(x, y, 0));
    }

    /*
    ** Returns Perlin noise value for (x, y, z) point
    ** in range [-1.0, 1.0f].
    ** Note: returns 0 when x, y and z are integers
    ** Smooth transitions are made using "natural" noise of doubles
    */
    double PerlinNoise::get(double x, double y, double z) const
    {
      // Floored x y and z
      const std::int32_t xi = static_cast<std::int32_t>(std::floor(x)) & (_permutationTableSize - 1);
      const std::int32_t yi = static_cast<std::int32_t>(std::floor(y)) & (_permutationTableSize - 1);
      const std::int32_t zi = static_cast<std::int32_t>(std::floor(z)) & (_permutationTableSize - 1);

      // Floating values of x and y
      const double xo = x - std::floor(x);
      const double yo = y - std::floor(y);
      const double zo = z - std::floor(z);

      // "Ease" offset values for interpolation
      const double u = _fade(xo);
      const double v = _fade(yo);
      const double w = _fade(zo);

      // Get random values for each corner
      const std::int32_t A = (_permutationTable[xi] + yi) % _permutationTableSize;
      const std::int32_t AA = (_permutationTable[A] + zi) % _permutationTableSize;
      const std::int32_t AB = (_permutationTable[(A + 1) % _permutationTableSize] + zi) % _permutationTableSize;
      const std::int32_t B = (_permutationTable[(xi + 1) % _permutationTableSize] + yi) % _permutationTableSize;
      const std::int32_t BA = (_permutationTable[B] + zi) % _permutationTableSize;
      const std::int32_t BB = (_permutationTable[(B + 1)  % _permutationTableSize] + zi) % _permutationTableSize;

      return (_lerp(w,
        _lerp(v,
          _lerp(u,
            _grad(_permutationTable[AA], xo, yo, zo),
				    _grad(_permutationTable[BA], xo - 1, yo, zo)),
				  _lerp(u,
            _grad(_permutationTable[AB], xo, yo - 1, zo),
				    _grad(_permutationTable[BB], xo - 1, yo - 1, zo))),
				_lerp(v,
          _lerp(u,
            _grad(_permutationTable[(AA + 1) % _permutationTableSize], xo, yo, zo - 1),
				    _grad(_permutationTable[(BA + 1) % _permutationTableSize], xo - 1, yo, zo - 1)),
				  _lerp(u,
            _grad(_permutationTable[(AB + 1) % _permutationTableSize], xo, yo - 1, zo - 1),
				    _grad(_permutationTable[(BB + 1) % _permutationTableSize], xo - 1, yo - 1, zo - 1)))));
    }

    /*
    ** Returns fractal Brownian motion (fBm) of Perlin noise for (x) point
    */
    double PerlinNoise::fractal(std::size_t octaves, double x) const
    {
      return (fractal(octaves, x, 0, 0));
    }

    /*
    ** Returns fractal Brownian motion (fBm) of Perlin noise for (x, y) point
    */
    double PerlinNoise::fractal(std::size_t octaves, double x, double y) const
    {
      return (fractal(octaves, x, y, 0));
    }

    /*
    ** Returns fractal Brownian motion (fBm) of Perlin noise for (x, y, z) point
    ** Note: fractal parameters are fixed, could be useful to play with them
    */
    double PerlinNoise::fractal(std::size_t octaves, double x, double y, double z) const
    {
      double output = 0.0f;
      double denom = 0.0f;
      double frequency = 0.1f;
      double amplitude = 1.0f;
      const double lacunarity = 2.0f;
      const double persistence = 0.5f;

      for (std::size_t i = 0; i < octaves; i++)
      {
        output += amplitude * get(x * frequency, y * frequency, z * frequency);
        denom += amplitude;

        frequency *= lacunarity;
        amplitude *= persistence;
      }

      return (output / denom);
    }

    /*
    ** Returns results of ease function 6t5-15t4+10t3
    ** create smooth transitions between cells
    */
    double PerlinNoise::_fade(double t) const
    {
      return (t * t * t * (t * (t * 6 - 15) + 10));
    }

    /*
    ** Returns interpolation value for t between a and b
    */
    double PerlinNoise::_lerp(double t, double a, double b) const
    {
      return (a + t * (b - a));
    }

    /*
    ** Returns weight of hash according to (x, y, z) vector direction
    */
    double PerlinNoise::_grad(std::uint32_t hash, double x, double y, double z) const
    {
      const std::uint8_t h = hash & 15;
			const double u = h < 8 ? x : y;
			const double v = h < 4 ? y : h == 12 || h == 14 ? x : z;

			return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
    }

    /*
    ** Create array of size _permutationTableSize and shuffle it
    */
    void PerlinNoise::_generatePermutationTable()
    {
      _permutationTable = new std::uint32_t[_permutationTableSize];
      
      // Initialize array
      for (std::size_t i = 0; i < _permutationTableSize; i++)
        _permutationTable[i] = i;
      
      // Shuffle it
      for (std::size_t i = 0; i < _permutationTableSize; i++)
      {
        const std::size_t picked = _rand.nextInt(_permutationTableSize);
        const std::uint32_t saved = _permutationTable[picked];

        _permutationTable[picked] = _permutationTable[i];
        _permutationTable[i] = saved;
      }
    }
  }
}
