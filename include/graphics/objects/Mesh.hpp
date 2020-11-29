#pragma once

#include <vector>
#include <cstdint>
#include <cstddef>

namespace ng
{
  namespace graphics
  {
    class Mesh
    {
      public:
        Mesh();
        ~Mesh();

        void setVertices(const std::vector<float> &);
        void setUVs(const std::vector<float> &);
        void setNormals(const std::vector<float> &);
        void setIndices(const std::vector<std::uint32_t> &);

        const std::vector<float> &getVertices() const;
        const std::vector<float> &getUVs() const;
        const std::vector<float> &getNormals() const;
        const std::vector<std::uint32_t> &getIndices() const;

      protected:
        std::vector<float> _vertices;
        std::vector<float> _uvs;
        std::vector<float> _normals;
        std::vector<std::uint32_t> _indices;
    };
  };
};