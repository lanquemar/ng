#include "GLFWWindow.hpp"
#include "exceptions/ErrorException.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      GLFWWindow::GLFWWindow()
      {
        _window = NULL;
        _initialized = false;
        _width = 0;
        _height = 0;
      }

      GLFWWindow::~GLFWWindow()
      {
        if (_initialized)
          glfwTerminate();
      }

      void GLFWWindow::open(const std::int32_t width, const std::int32_t height)
      {
        if (glfwInit() == GLFW_FALSE)
          _throwGLFWError();

        _initialized = true;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        #ifdef __APPLE__
          glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        _window = glfwCreateWindow(width, height, "Prototype", NULL, NULL);
        if (_window == NULL)
          _throwGLFWError();

        _width = width;
        _height = height;

        glfwMakeContextCurrent(_window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
          throw ErrorException("Failed to initialize OpenGL extensions");
        
        glEnable(GL_DEPTH_TEST);
      }

      void GLFWWindow::close()
      {
        glfwSetWindowShouldClose(_window, true);
      }

      bool GLFWWindow::isOpen()
      {
        return (!glfwWindowShouldClose(_window));
      }

      void GLFWWindow::draw()
      {
        glfwSwapBuffers(_window);
      }

      void GLFWWindow::pollEvents()
      {
        glfwPollEvents();
      }

      const std::int32_t GLFWWindow::getWidth() const
      {
        return (_width);
      }

      const std::int32_t GLFWWindow::getHeight() const
      {
        return (_height);
      }

      void GLFWWindow::_throwGLFWError()
      {
        const char *msg;
        
        if (glfwGetError(&msg) != GLFW_NO_ERROR)
          throw ErrorException(msg);
      }
    }
  }
}