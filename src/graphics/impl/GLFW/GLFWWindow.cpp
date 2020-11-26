#include "GLFWWindow.hpp"
#include "exceptions/ErrorException.hpp"

// GLFW callbacks
static void onKey(GLFWwindow *window, int key, int scancode, int actions, int mods)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onKey(key, scancode, actions, mods);
}

static void onResize(GLFWwindow *window, int width, int height)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onResize(width, height);
}

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
        if (!_initialized && glfwInit() == GLFW_FALSE)
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

        // Setup GLFW events callbacks
        glfwSetWindowUserPointer(_window, this);
        glfwSetKeyCallback(_window, ::onKey);
        glfwSetWindowSizeCallback(_window, ::onResize);

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

      std::int32_t GLFWWindow::getWidth() const
      {
        return (_width);
      }

      std::int32_t GLFWWindow::getHeight() const
      {
        return (_height);
      }

      void GLFWWindow::onKey(int key, int scancode, int actions, int mods)
      {
        // TODO: implement
      }

      void GLFWWindow::onResize(int width, int height)
      {
        _width = width;
        _height = height;
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