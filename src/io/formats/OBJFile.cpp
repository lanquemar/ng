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

#include <map>
#include <tuple>

#include "utils/Logger.hpp"
#include "io/formats/OBJFile.hpp"
#include "io/File.hpp"

#define OBJ_SPACES " \t"
#define OBJ_RETURNS "\n\r"

namespace ng
{
  namespace io
  {
    OBJFile::OBJFile()
    {
    }

    OBJFile::~OBJFile()
    {
    }

    void OBJFile::loadFromFile(ng::graphics::Mesh &mesh,
      const std::string &filename)
    {
      ng::io::Buffer buff;
      ng::io::File file;

      reset();
      file.open(filename, ng::io::File::READ | ng::io::File::TEXT);
      file.readAll(buff);
      _parseOBJFile(buff);
      _generate(mesh);
      reset();
      LOG(DEBUG) << "OBJ File parsing done, results:" << std::endl;
      LOG(DEBUG) << mesh.getVertices().size() << " vertices" << std::endl;
      LOG(DEBUG) << mesh.getUVs().size() << " uvs" << std::endl;
      LOG(DEBUG) << mesh.getNormals().size() << " normals" << std::endl;
      LOG(DEBUG) << mesh.getIndices().size() << " indices" << std::endl;
    }

    void OBJFile::reset()
    {
      _pos = 0;
      _OBJvertices.clear();
      _OBJtexcoords.clear();
      _OBJnormals.clear();
      _OBJfaces.clear();
    }

    void OBJFile::_parseOBJFile(ng::io::Buffer &buff)
    {
      while (_pos < buff.size() && _parseOBJLine(buff));
    }

    bool OBJFile::_parseOBJLine(ng::io::Buffer &buff)
    {
      // Consume all trailing spaces and empty lines
      while (_consume(buff, OBJ_SPACES) || _consume(buff, OBJ_RETURNS));

      switch (buff[_pos])
      {
        case '#':
          _consumeUntil(buff, OBJ_RETURNS);
          break;

        case 'o':
          _consumeUntil(buff, OBJ_RETURNS);
          break;

        case 'f':
          _pos += 1;
          _parseFace(buff);
          _consumeUntil(buff, OBJ_RETURNS);
          break;

        case 'v':
          switch (buff[_pos + 1])
          {
            case ' ':
              _pos += 2;
              _parseVertice(buff);
              _consumeUntil(buff, OBJ_RETURNS);
              break;

            case 't':
              _pos += 3;
              _parseUVTexture(buff);
              _consumeUntil(buff, OBJ_RETURNS);
              break;

            case 'n':
              _pos += 3;
              _parseNormal(buff);
              _consumeUntil(buff, OBJ_RETURNS);
              break;

            default:
              // !! unexpected character
              return (false);
          }
          break;

        default:
          // !! unexpected character
          return (false);
      }

      _consume(buff, OBJ_RETURNS);
      return (true);
    }

    bool OBJFile::_consume(ng::io::Buffer &buff,
      const std::string &alphabet)
    {
      std::size_t backup = _pos;

      while (_pos < buff.size() &&
        alphabet.find(buff[_pos]) != std::string::npos)
        _pos++;
      return (!(backup == _pos));
    }

    bool OBJFile::_consumeUntil(ng::io::Buffer &buff,
      const std::string &alphabet)
    {
      std::size_t backup = _pos;

      while (_pos < buff.size() &&
        alphabet.find(buff[_pos]) == std::string::npos)
        _pos++;
      return (!(backup == _pos));
    }

    void OBJFile::_parseVertice(ng::io::Buffer &buff)
    {
      float x, y, z;

      #ifdef _WIN32
        sscanf_s((const char *)(buff.getPtr() + _pos), "%f %f %f", &x, &y, &z);
      #else
        sscanf((const char *)(buff.getPtr() + _pos), "%f %f %f", &x, &y, &z);
      #endif

      _OBJvertices.push_back(x);
      _OBJvertices.push_back(y);
      _OBJvertices.push_back(z);
    }

    void OBJFile::_parseUVTexture(ng::io::Buffer &buff)
    {
      float x, y;

      #ifdef _WIN32
        sscanf_s((const char *)(buff.getPtr() + _pos), "%f %f", &x, &y);
      #else
        sscanf((const char *)(buff.getPtr() + _pos), "%f %f", &x, &y);
      #endif

      _OBJtexcoords.push_back(x);
      _OBJtexcoords.push_back(y);
    }

    void OBJFile::_parseNormal(ng::io::Buffer &buff)
    {
      float x, y, z;

      #ifdef _WIN32
        sscanf_s((const char *)(buff.getPtr() + _pos), "%f %f %f", &x, &y, &z);
      #else
        sscanf((const char *)(buff.getPtr() + _pos), "%f %f %f", &x, &y, &z);
      #endif

      _OBJnormals.push_back(x);
      _OBJnormals.push_back(y);
      _OBJnormals.push_back(z);
    }

    void OBJFile::_parseFace(ng::io::Buffer &buff)
    {
      int x1, y1, z1;
      int x2, y2, z2;
      int x3, y3, z3;

      #ifdef _WIN32
        sscanf_s((const char *)(buff.getPtr() + _pos),
          "%d/%d/%d %d/%d/%d %d/%d/%d",
          &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
      #else
        sscanf((const char *)(buff.getPtr() + _pos),
          "%d/%d/%d %d/%d/%d %d/%d/%d",
          &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
      #endif

      _OBJfaces.push_back(x1);
      _OBJfaces.push_back(y1);
      _OBJfaces.push_back(z1);

      _OBJfaces.push_back(x2);
      _OBJfaces.push_back(y2);
      _OBJfaces.push_back(z2);

      _OBJfaces.push_back(x3);
      _OBJfaces.push_back(y3);
      _OBJfaces.push_back(z3);
    }

    // OBJ format imposes 3 different indexes (vertice, uv texture, normal)
    // for each vertice where OpenGL needs only one index for each vertice
    // For the conversion, we store a unique tuple (vertice, uv texture, normal)
    // for the OBJ format linked to a unique OpenGL index
    void OBJFile::_generate(ng::graphics::Mesh &mesh)
    {
      std::map<
        std::tuple<std::size_t, std::size_t, std::size_t>,
        std::size_t> objIndices;
      std::vector<float> vertices, uvs, normals;
      std::vector<std::uint32_t> indices;

      for (std::size_t i = 0; i < _OBJfaces.size(); i += 3)
      {
        auto it = objIndices.find(
          std::tuple<std::size_t, std::size_t, std::size_t>(
            _OBJfaces[i], _OBJfaces[i + 1], _OBJfaces[i + 2]));

        if (it != objIndices.end())
          indices.push_back(it->second);
        else
        {
          std::size_t newIndex = vertices.size() / 3;
          std::size_t objVerticeIndex = (_OBJfaces[i] - 1) * 3;
          std::size_t objTexcoordIndex = (_OBJfaces[i + 1] - 1) * 2;
          std::size_t objNormalsIndex = (_OBJfaces[i + 2] - 1) * 3;

          objIndices[std::tuple<std::size_t, std::size_t, std::size_t>(
            _OBJfaces[i], _OBJfaces[i + 1], _OBJfaces[i + 2])] = newIndex;

          vertices.push_back(_OBJvertices[objVerticeIndex]);
          vertices.push_back(_OBJvertices[objVerticeIndex + 1]);
          vertices.push_back(_OBJvertices[objVerticeIndex + 2]);

          uvs.push_back(_OBJtexcoords[objTexcoordIndex]);
          uvs.push_back(_OBJtexcoords[objTexcoordIndex + 1]);

          normals.push_back(_OBJnormals[objNormalsIndex]);
          normals.push_back(_OBJnormals[objNormalsIndex + 1]);
          normals.push_back(_OBJnormals[objNormalsIndex + 2]);

          indices.push_back(newIndex);
        }
      }

      mesh.setVertices(vertices);
      mesh.setUVs(uvs);
      mesh.setNormals(normals);
      mesh.setIndices(indices);
    }
  } /* namespace io */
} /* namespace ng */
