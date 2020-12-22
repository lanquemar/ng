#include "GLFWKeyboard.hpp"
#include "GLFWWindow.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      GLFWKeyboard::GLFWKeyboard(GLFWWindow *window)
      {
        _window = window->getHandle();
      }

      GLFWKeyboard::~GLFWKeyboard()
      {

      }

      bool GLFWKeyboard::isKeyPressed(ng::graphics::Keyboard::Key key)
      {
        if (key > 0 && key < ng::graphics::impl::GLFWKeyboard::ngToGlfwSize)
          return (::glfwGetKey(_window, ng::graphics::impl::GLFWKeyboard::ngToGlfw[key]) == GLFW_PRESS);
        return (false);
      }
    }
  }
}
