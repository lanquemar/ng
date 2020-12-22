#include "GLFWMouse.hpp"
#include "GLFWWindow.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      GLFWMouse::GLFWMouse(GLFWWindow *window)
      {
        _window = window->getHandle();
      }

      GLFWMouse::~GLFWMouse()
      {

      }

      bool GLFWMouse::isButtonPressed(ng::graphics::Mouse::Key button) const
      {
        if (button > 0 && button < ng::graphics::impl::GLFWMouse::ngToGlfwSize)
          return (::glfwGetMouseButton(_window, ng::graphics::impl::GLFWMouse::ngToGlfw[button]) == GLFW_PRESS);
        return (false);
      }

      glm::ivec2 GLFWMouse::getPosition() const
      {
        double x, y;

        ::glfwGetCursorPos(_window, &x, &y);
        return (glm::ivec2(x, y));
      }
    }
  }
}
