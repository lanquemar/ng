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
      class GLFWWindow;

      class GLFWMouse : public ng::graphics::Mouse
      {
        public:
          GLFWMouse(GLFWWindow *);
          ~GLFWMouse();

          bool isButtonPressed(ng::graphics::Mouse::Key) const override;
          glm::ivec2 getPosition() const override;

          static const std::size_t glfwToNgSize;
          static const ng::graphics::Mouse::Key glfwToNg[];

          static const std::size_t ngToGlfwSize;
          static const int ngToGlfw[];

        private:
          ::GLFWwindow *_window;
      };
    };
  };
};
