#pragma once

#include <glm/gtc/type_ptr.hpp>

namespace ng
{
  namespace graphics
  {
    class Mouse
    {
      public:
        // See further down for declaration
        enum Key: int;

        virtual ~Mouse() {}

        virtual bool isButtonPressed(ng::graphics::Mouse::Key) const = 0;
        virtual glm::ivec2 getPosition() const = 0;

        enum Key: int
        {
          UNKNOWN = -1,
          BUTTON_1 = 0,
          BUTTON_2,
          BUTTON_3,
          BUTTON_4,
          BUTTON_5,
          BUTTON_6,
          BUTTON_7,
          BUTTON_8,
          BUTTON_9
        };
    };
  };
};
