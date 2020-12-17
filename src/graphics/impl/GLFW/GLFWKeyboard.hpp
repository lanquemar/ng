#pragma once

#include <cstddef>

#include <GLFW/glfw3.h>

#include "graphics/Keyboard.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWKeyboard
      {
        public:
          static const std::size_t mappingSize;
          static const ng::graphics::Keyboard::Key mapping[];
      };
    };
  };
};
