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
      class GLFWWindow;

      class GLFWKeyboard : public ng::graphics::Keyboard
      {
        public:
          GLFWKeyboard(GLFWWindow *);
          ~GLFWKeyboard();

          bool isKeyPressed(ng::graphics::Keyboard::Key) override;

          static const std::size_t glfwToNgSize;
          static const ng::graphics::Keyboard::Key glfwToNg[];

          static const std::size_t ngToGlfwSize;
          static const int ngToGlfw[];

        private:
          ::GLFWwindow *_window;
      };
    };
  };
};
