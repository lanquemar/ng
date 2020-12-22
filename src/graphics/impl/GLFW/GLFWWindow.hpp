#pragma once

#include <GLFW/glfw3.h>

#include <cstdint>

#include "graphics/Window.hpp"
#include "GLFWKeyboard.hpp"
#include "GLFWMouse.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWWindow : public Window
      {
        public:
          GLFWWindow();
          ~GLFWWindow();

          void open(const std::int32_t = 800, const std::int32_t = 600) override;
          void close() override;
          bool isOpen() override;

          void draw() override;
          void pollEvents(ng::graphics::Event &) override;

          std::int32_t getWidth() const override;
          std::int32_t getHeight() const override;

          ng::graphics::Keyboard *getKeyboard() override;
          ng::graphics::Mouse *getMouse() override;

          void onKey(int, int, int, int);
          void onText(unsigned int);
          void onResize(int, int);
          void onMouseMove(double, double);
          void onMouseEnter(int);
          void onMouseButton(int, int, int);
          void onMouseScroll(double, double);

          ::GLFWwindow *getHandle() const;

        private:
          void _throwGLFWError();

          ::GLFWwindow *_window;
          bool _initialized;
          std::int32_t _width;
          std::int32_t _height;

          ng::graphics::impl::GLFWKeyboard *_keyboard;
          ng::graphics::impl::GLFWMouse *_mouse;

          ng::graphics::Event *_event;
      };
    };
  };
};
