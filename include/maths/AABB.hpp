// MIT License
//
// Copyright (c) 2021 Adrien Vasseur
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <iostream>
#include <glm/glm.hpp>

#include "maths/Ray.hpp"

namespace ng
{
  namespace maths
  {
    class AABB
    {
      public:
        AABB();
        AABB(glm::vec3, glm::vec3);
        ~AABB();

        bool collide(const ng::maths::Ray &) const;

        AABB operator+(const AABB &) const;

        glm::vec3 getPosition() const;
        glm::vec3 getSize() const;

        void setPosition(glm::vec3);
        void setSize(glm::vec3);

      private:
        glm::vec3 _pos;
        glm::vec3 _size;
    };
  }; /* namespace maths */
}; /* namespace ng */

std::ostream& operator<<(std::ostream&, const ng::maths::AABB&);
