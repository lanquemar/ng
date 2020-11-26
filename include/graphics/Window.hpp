#pragma once

#include <cstdint>

namespace ng
{
  namespace graphics
  {
    class Window
    {
      public:
        virtual ~Window() {}

        virtual void open(const std::int32_t = 800, const std::int32_t = 600) = 0;
        virtual void close() = 0;
        virtual bool isOpen() = 0;

        virtual void draw() = 0;
        virtual void pollEvents() = 0;

        virtual std::int32_t getWidth() const = 0;
        virtual std::int32_t getHeight() const = 0;

        static Window* create();
    };
  };
};