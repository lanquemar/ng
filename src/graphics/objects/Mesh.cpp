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
  };
};