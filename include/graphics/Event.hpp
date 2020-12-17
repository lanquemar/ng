#pragma once

#include <cstdint>

#include "Keyboard.hpp"
#include "Mouse.hpp"

namespace ng
{
  namespace graphics
  {
    class Event
    {
      public:
        enum Type
        {
          NONE,
          CLOSED,
          RESIZED,
          KEY_PRESSED,
          KEY_RELEASED,
          MOUSE_PRESSED,
          MOUSE_RELEASED,
          MOUSE_MOVED,
          MOUSE_ENTERED,
          MOUSE_LEFT,
          MOUSE_SCROLL
        };

        Type type;

        struct SizeInfo
        {
          std::uint32_t width;
          std::uint32_t height;
        };

        struct PositionInfo
        {
          std::uint32_t x;
          std::uint32_t y;
        };

        struct DeltaInfo
        {
          std::int32_t x;
          std::int32_t y;
        };

        struct KeyInfo
        {
          Keyboard::Key key;
          bool alt;
          bool control;
          bool shift;
          bool system;
          bool capslock;
          bool numlock;
        };

        struct ButtonInfo
        {
          Mouse::Key key;
          bool alt;
          bool control;
          bool shift;
          bool system;
          bool capslock;
          bool numlock;
        };

        union
        {
          KeyInfo key;
          ButtonInfo button;
          SizeInfo size;
          PositionInfo pos;
          DeltaInfo delta;
        };
    };
  };
};
