#pragma once

namespace ng
{
  namespace maths
  {
    class Random
    {
      public:
        Random();
        ~Random();

        int nextInt();
        int nextInt(int);
        int nextInt(int, int);

        float nextUnit();

        void reset();
    };
  };
};