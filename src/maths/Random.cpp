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
      // (on Windows, first numbers are sometimes pretty close when seed is close)
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
      return (((float) std::rand()) / ((float) RAND_MAX));
    }

    void Random::reset()
    {
      std::srand((unsigned) time(0));
    }
  }
}

