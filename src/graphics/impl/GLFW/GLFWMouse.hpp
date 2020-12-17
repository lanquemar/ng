#pragma once

#include <cstddef>

#include <GLFW/glfw3.h>

#include "graphics/Mouse.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWMouse
      {
        public:
          static const std::size_t mappingSize;
          static const ng::graphics::Mouse::Key mapping[];
      };
    };
  };
};
