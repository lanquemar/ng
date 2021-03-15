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

#include "maths/AABB.hpp"

namespace ng
{
  namespace maths
  {
    AABB::AABB() : _pos(glm::vec3(0, 0, 0)), _size(glm::vec3(0, 0, 0))
    {
    }

    AABB::AABB(glm::vec3 pos, glm::vec3 size) : _pos(pos), _size(size)
    {
    }

    AABB::~AABB()
    {
    }

    bool AABB::collide(const ng::maths::Ray &) const
    {
      return (true);
    }

    AABB AABB::operator+(const AABB &other) const
    {
      glm::vec3 minPos = glm::min(_pos, other.getPosition());
      glm::vec3 maxPos = glm::max(_pos + _size, other.getPosition() + other.getSize());

      return (AABB(minPos, maxPos - minPos));
    }

    glm::vec3 AABB::getPosition() const
    {
      return (_pos);
    }
    
    glm::vec3 AABB::getSize() const
    {
      return (_size);
    }

    void AABB::setPosition(glm::vec3 pos)
    {
      _pos = pos;
    }
    
    void AABB::setSize(glm::vec3 size)
    {
      _size = size;
    }
  }; /* namespace maths */
}; /* namespace ng */

std::ostream& operator<<(std::ostream& os, const ng::maths::AABB& aabb)
{
  os << "AABB(Pos(" <<
    aabb.getPosition().x << ", " <<
    aabb.getPosition().y << ", " <<
    aabb.getPosition().z << "), Size(" <<
    aabb.getSize().x << ", " <<
    aabb.getSize().y << ", " <<
    aabb.getSize().z << "))";
  return (os);
}
