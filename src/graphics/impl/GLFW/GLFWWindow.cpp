#include <glad/glad.h>

#include "GLFWWindow.hpp"
#include "exceptions/ErrorException.hpp"

// GLFW callbacks
static void onKey(GLFWwindow *window, int key, int scancode, int actions, int mods)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onKey(key, scancode, actions, mods);
}

static void onText(GLFWwindow *window, unsigned int codepoint)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onText(codepoint);
}

static void onResize(GLFWwindow *window, int width, int height)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onResize(width, height);
}

static void onMouseMove(GLFWwindow* window, double xpos, double ypos)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onMouseMove(xpos, ypos);
}

static void onMouseEnter(GLFWwindow* window, int entered)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onMouseEnter(entered);
}

static void onMouseButton(GLFWwindow* window, int button, int action, int mods)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onMouseButton(button, action, mods);
}

static void onMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
  ng::graphics::impl::GLFWWindow* obj = (ng::graphics::impl::GLFWWindow *) glfwGetWindowUserPointer(window);
  obj->onMouseScroll(xoffset, yoffset);
}

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      GLFWWindow::GLFWWindow()
      {
        _window = nullptr;
        _initialized = false;
        _width = 0;
        _height = 0;
        _keyboard = nullptr;
        _mouse = nullptr;
        _event = nullptr;
      }

      GLFWWindow::~GLFWWindow()
      {
        if (_mouse)
          delete _mouse;
        if (_keyboard)
          delete _keyboard;
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
        glfwSetInputMode(_window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
        glfwSetWindowUserPointer(_window, this);
        glfwSetKeyCallback(_window, ::onKey);
        glfwSetCharCallback(_window, ::onText);
        glfwSetWindowSizeCallback(_window, ::onResize);
        glfwSetCursorPosCallback(_window, ::onMouseMove);
        glfwSetCursorEnterCallback(_window, ::onMouseEnter);
        glfwSetMouseButtonCallback(_window, ::onMouseButton);
        glfwSetScrollCallback(_window, ::onMouseScroll);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
          throw ErrorException("Failed to initialize OpenGL extensions");
        
        glEnable(GL_DEPTH_TEST);

        _keyboard = new GLFWKeyboard(this);
        _mouse = new GLFWMouse(this);
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

      void GLFWWindow::pollEvents(ng::graphics::Event &event)
      {
        // TODO: here only one event handled at a time
        // we should create an event queue to stack them
        _event = &event;
        _event->type = ng::graphics::Event::NONE;
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

      ng::graphics::Keyboard *GLFWWindow::getKeyboard()
      {
        return (_keyboard);
      }

      ng::graphics::Mouse *GLFWWindow::getMouse()
      {
        return (_mouse);
      }

      void GLFWWindow::onKey(int key, int scancode, int actions, int mods)
      {
        // Setup event type
        switch (actions)
        {
          case GLFW_RELEASE:
            _event->type = ng::graphics::Event::KEY_RELEASED;
            break;

          case GLFW_PRESS:
            _event->type = ng::graphics::Event::KEY_PRESSED;
            break;

          case GLFW_REPEAT:
            _event->type = ng::graphics::Event::KEY_PRESSED;
            break;
        }

        // Setup key value
        if (key != GLFW_KEY_UNKNOWN && key > 0 &&
          static_cast<std::size_t>(key) < ng::graphics::impl::GLFWKeyboard::glfwToNgSize)
          _event->key.key = ng::graphics::impl::GLFWKeyboard::glfwToNg[key];
        else
          _event->key.key = ng::graphics::Keyboard::UNKNOWN;

        // Setup mods
        _event->key.alt = (mods & GLFW_MOD_ALT);
        _event->key.control = (mods & GLFW_MOD_CONTROL);
        _event->key.shift = (mods & GLFW_MOD_SHIFT);
        _event->key.system = (mods & GLFW_MOD_SUPER);
        _event->key.capslock = (mods & GLFW_MOD_CAPS_LOCK);
        _event->key.numlock = (mods & GLFW_MOD_NUM_LOCK);
      }

      void GLFWWindow::onText(unsigned int codepoint)
      {
        // TODO: implement
      }

      void GLFWWindow::onResize(int width, int height)
      {
        // Discard the 0 x 0 event
        if (width > 0 && height > 0)
        {
          _width = width;
          _height = height;

          _event->type = ng::graphics::Event::RESIZED;
          _event->size.width = static_cast<std::uint32_t>(width);
          _event->size.height = static_cast<std::uint32_t>(height);
        }
      }

      void GLFWWindow::onMouseMove(double xpos, double ypos)
      {
        _event->type = ng::graphics::Event::MOUSE_MOVED;
        _event->pos.x = static_cast<std::uint32_t>(xpos);
        _event->pos.y = static_cast<std::uint32_t>(ypos);
      }

      void GLFWWindow::onMouseEnter(int entered)
      {
        if (entered)
          _event->type = ng::graphics::Event::MOUSE_ENTERED;
        else
          _event->type = ng::graphics::Event::MOUSE_LEFT;
      }

      void GLFWWindow::onMouseButton(int button, int actions, int mods)
      {
        // Setup event type
        switch (actions)
        {
          case GLFW_RELEASE:
            _event->type = ng::graphics::Event::MOUSE_RELEASED;
            break;

          case GLFW_PRESS:
            _event->type = ng::graphics::Event::MOUSE_PRESSED;
            break;

          case GLFW_REPEAT:
            _event->type = ng::graphics::Event::MOUSE_PRESSED;
            break;
        }

        // Setup key value
        if (button != GLFW_KEY_UNKNOWN && button > 0 &&
          static_cast<std::size_t>(button) < ng::graphics::impl::GLFWMouse::glfwToNgSize)
          _event->button.key = ng::graphics::impl::GLFWMouse::glfwToNg[button];
        else
          _event->button.key = ng::graphics::Mouse::UNKNOWN;

        // Setup mods
        _event->button.alt = (mods & GLFW_MOD_ALT);
        _event->button.control = (mods & GLFW_MOD_CONTROL);
        _event->button.shift = (mods & GLFW_MOD_SHIFT);
        _event->button.system = (mods & GLFW_MOD_SUPER);
        _event->button.capslock = (mods & GLFW_MOD_CAPS_LOCK);
        _event->button.numlock = (mods & GLFW_MOD_NUM_LOCK);
      }

      void GLFWWindow::onMouseScroll(double xoffset, double yoffset)
      {
        _event->type = ng::graphics::Event::MOUSE_SCROLL;
        _event->delta.x = static_cast<std::int32_t>(xoffset);
        _event->delta.y = static_cast<std::int32_t>(yoffset);
      }

      void GLFWWindow::_throwGLFWError()
      {
        const char *msg;
        
        if (glfwGetError(&msg) != GLFW_NO_ERROR)
          throw ErrorException(msg);
      }

      ::GLFWwindow *GLFWWindow::getHandle() const
      {
        return (_window);
      }
    }
  }
}
