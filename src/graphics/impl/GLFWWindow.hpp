#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      class GLFWWindow
      {
        public:
          GLFWWindow();
          ~GLFWWindow();

          void open(const std::int32_t = 800, const std::int32_t = 600);
          void close();
          bool isOpen();

          void draw();
          void pollEvents();

          const std::int32_t getWidth() const;
          const std::int32_t getHeight() const;

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