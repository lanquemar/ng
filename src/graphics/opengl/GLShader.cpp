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

#include "graphics/opengl/GLShader.hpp"
#include "utils/Logger.hpp"
#include "io/File.hpp"
#include "io/Buffer.hpp"
#include "exceptions/ErrorException.hpp"

namespace ng
{
  namespace graphics
  {
    GLShader::GLShader(std::string vertexFilename,
      std::string fragmentFilename) :
      _vertexFilename(vertexFilename),
      _fragmentFilename(fragmentFilename)
    {
      _vertexID = 0;
      _fragmentID = 0;
      _programID = 0;
    }

    GLShader::~GLShader()
    {
      _deleteAll();
    }

    bool GLShader::compile()
    {
      if (!GLShader::_compileShader(_vertexID,
        GL_VERTEX_SHADER, _vertexFilename))
        return (false);
      if (!GLShader::_compileShader(_fragmentID,
        GL_FRAGMENT_SHADER, _fragmentFilename))
        return (false);
      if (!GLShader::_compileProgram(_programID,
        _vertexID, _fragmentID))
        return (false);
      return (true);
    }

    GLuint GLShader::getProgramID() const
    {
      return (_programID);
    }

    void GLShader::_getCompileLog(GLuint obj)
    {
      GLint size;
      char *msg;

      size = 0;
      if (glIsShader(obj) == GL_TRUE)
        glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &size);
      else if (glIsProgram(obj) == GL_TRUE)
        glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &size);
      else
      {
        LOG(ERROR) <<
          "GLShader compilation failure: unknown object type" << std::endl;
        return;
      }
      msg = new char[size + 1];
      if (glIsShader(obj) == GL_TRUE)
        glGetShaderInfoLog(obj, size, NULL, msg);
      else if (glIsProgram(obj) == GL_TRUE)
        glGetProgramInfoLog(obj, size, NULL, msg);
      msg[size] = '\0';
      LOG(ERROR) << "GLShader compilation failure: " << msg << std::endl;
      delete[] msg;
    }

    bool GLShader::_compileShader(GLuint &shader, GLenum type,
      std::string const &filename)
    {
      ng::io::File file;
      ng::io::Buffer buff;
      GLchar *source;
      GLint compileState;

      compileState = 0;
      if ((shader = glCreateShader(type)) == 0)
        return (false);
      try
      {
        file.open(filename, ng::io::File::READ | ng::io::File::TEXT);
        file.readAll(buff);
      }
      catch (ng::ErrorException &e)
      {
        LOG(ERROR) <<
          "GLShader compilation failure: cannot open file: " <<
          e.what() << std::endl;
        glDeleteShader(shader);
        return (false);
      }
      source = reinterpret_cast<GLchar *>(buff.getPtr());
      glShaderSource(shader, 1, (const GLchar **) &source, NULL);
      glCompileShader(shader);
      glGetShaderiv(shader, GL_COMPILE_STATUS, &compileState);
      if (compileState != GL_TRUE)
      {
        GLShader::_getCompileLog(shader);
        glDeleteShader(shader);
        return (false);
      }
      return (true);
    }

    bool GLShader::_compileProgram(GLuint &program, GLuint vertex,
      GLuint fragment)
    {
      GLint status;

      status = 0;
      if ((program = glCreateProgram()) == 0)
        return (false);
      glAttachShader(program, vertex);
      glAttachShader(program, fragment);
      glLinkProgram(program);
      glGetProgramiv(program, GL_LINK_STATUS, &status);
      if (status != GL_TRUE)
      {
        GLShader::_getCompileLog(program);
        glDeleteProgram(program);
        return (false);
      }
      return (true);
    }

    void GLShader::_deleteAll()
    {
      if (glIsShader(_vertexID) == GL_TRUE)
        glDeleteShader(_vertexID);
      if (glIsShader(_fragmentID) == GL_TRUE)
        glDeleteShader(_fragmentID);
      if (glIsProgram(_programID) == GL_TRUE)
        glDeleteProgram(_programID);

      _vertexID = 0;
      _fragmentID = 0;
      _programID = 0;
    }
  } /* namespace graphics */
} /* namespace ng */
