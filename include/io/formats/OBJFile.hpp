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

#include <string>
#include <vector>
#include <cstdint>
#include <cstddef>

#include "io/Buffer.hpp"
#include "graphics/objects/Mesh.hpp"

namespace ng
{
  namespace io
  {
    class OBJFile
    {
      public:
        OBJFile();
        ~OBJFile();

        void loadFromFile(ng::graphics::Mesh &, const std::string &);
        void reset();

      private:
        void _parseOBJFile(ng::io::Buffer &);
        bool _parseOBJLine(ng::io::Buffer &);
        bool _consume(ng::io::Buffer &, const std::string &);
        bool _consumeUntil(ng::io::Buffer &, const std::string &);

        void _parseVertice(ng::io::Buffer &);
        void _parseUVTexture(ng::io::Buffer &);
        void _parseNormal(ng::io::Buffer &);
        void _parseFace(ng::io::Buffer &);

        void _generate(ng::graphics::Mesh &);

        std::size_t _pos;
        std::vector<float> _OBJvertices;
        std::vector<float> _OBJtexcoords;
        std::vector<float> _OBJnormals;
        std::vector<std::uint32_t> _OBJfaces;
    };
  }; /* namespace io */
}; /* namespace ng */
