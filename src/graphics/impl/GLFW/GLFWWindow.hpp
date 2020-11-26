#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>

#include "graphics/Window.hpp"

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
          void pollEvents() override;

          std::int32_t getWidth() const override;
          std::int32_t getHeight() const override;

          void onKey(int, int, int, int);
          void onResize(int, int);

        private:
          void _throwGLFWError();

          GLFWwindow *_window;
          bool _initialized;
          std::int32_t _width;
          std::int32_t _height;
      };
    };
  };
};