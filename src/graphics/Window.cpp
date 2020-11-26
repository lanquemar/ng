#include "graphics/Window.hpp"

#include "impl/GLFW/GLFWWindow.hpp"

namespace ng
{
  namespace graphics
  {
    Window* Window::create()
    {
      return (new ng::graphics::impl::GLFWWindow());
    }
  }
}