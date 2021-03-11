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

#include "graphics/objects/Mesh.hpp"

namespace ng
{
  namespace graphics
  {
    Mesh::Mesh()
    {
    }

    Mesh::~Mesh()
    {
    }

    void Mesh::setVertices(const std::vector<float> &vertices)
    {
      // Data copy: slow
      _vertices = vertices;
    }

    void Mesh::setUVs(const std::vector<float> &uvs)
    {
      // Data copy: slow
      _uvs = uvs;
    }

    void Mesh::setNormals(const std::vector<float> &normals)
    {
      // Data copy: slow
      _normals = normals;
    }

    void Mesh::setIndices(const std::vector<std::uint32_t> &indices)
    {
      // Data copy: slow
      _indices = indices;
    }

    const std::vector<float> &Mesh::getVertices() const
    {
      return (_vertices);
    }

    const std::vector<float> &Mesh::getUVs() const
    {
      return (_uvs);
    }

    const std::vector<float> &Mesh::getNormals() const
    {
      return (_normals);
    }

    const std::vector<std::uint32_t> &Mesh::getIndices() const
    {
      return (_indices);
    }
  }; /* namespace graphics */
}; /* namespace ng */
