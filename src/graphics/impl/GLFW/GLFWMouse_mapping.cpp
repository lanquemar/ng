#include <cstddef>

#include "GLFWMouse.hpp"

#include "graphics/Mouse.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      const std::size_t GLFWMouse::glfwToNgSize = GLFW_MOUSE_BUTTON_8 + 1;
      const ng::graphics::Mouse::Key GLFWMouse::glfwToNg[glfwToNgSize] = {
        ng::graphics::Mouse::BUTTON_1, // 0 GLFW_MOUSE_BUTTON_1
        ng::graphics::Mouse::BUTTON_2, // 1 GLFW_MOUSE_BUTTON_2
        ng::graphics::Mouse::BUTTON_3, // 2 GLFW_MOUSE_BUTTON_3
        ng::graphics::Mouse::BUTTON_4, // 3 GLFW_MOUSE_BUTTON_4
        ng::graphics::Mouse::BUTTON_5, // 4 GLFW_MOUSE_BUTTON_5
        ng::graphics::Mouse::BUTTON_6, // 5 GLFW_MOUSE_BUTTON_6
        ng::graphics::Mouse::BUTTON_7, // 6 GLFW_MOUSE_BUTTON_7
        ng::graphics::Mouse::BUTTON_8  // 7 GLFW_MOUSE_BUTTON_8
      };

      const std::size_t GLFWMouse::ngToGlfwSize = ng::graphics::Mouse::BUTTON_9 + 1;
      const int GLFWMouse::ngToGlfw[ngToGlfwSize] = {
        GLFW_MOUSE_BUTTON_1, // 0 ng::graphics::Mouse::BUTTON_1
        GLFW_MOUSE_BUTTON_2, // 1 ng::graphics::Mouse::BUTTON_2
        GLFW_MOUSE_BUTTON_3, // 2 ng::graphics::Mouse::BUTTON_3
        GLFW_MOUSE_BUTTON_4, // 3 ng::graphics::Mouse::BUTTON_4
        GLFW_MOUSE_BUTTON_5, // 4 ng::graphics::Mouse::BUTTON_5
        GLFW_MOUSE_BUTTON_6, // 5 ng::graphics::Mouse::BUTTON_6
        GLFW_MOUSE_BUTTON_7, // 6 ng::graphics::Mouse::BUTTON_7
        GLFW_MOUSE_BUTTON_8, // 7 ng::graphics::Mouse::BUTTON_8
        GLFW_KEY_UNKNOWN,    // 8 ng::graphics::Mouse::BUTTON_9
      };
    }
  }
}
