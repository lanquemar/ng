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
  };
};