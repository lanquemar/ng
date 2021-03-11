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

#include <glad/glad.h>

#include <string>

namespace ng
{
  namespace graphics
  {
    class GLShader
    {
      public:
        GLShader(std::string, std::string);
        ~GLShader();

        bool compile();

        GLuint getProgramID() const;

      private:
        static void _getCompileLog(GLuint);
        static bool _compileShader(GLuint &, GLenum, std::string const &);
        static bool _compileProgram(GLuint &, GLuint, GLuint);
        void _deleteAll();


        std::string _vertexFilename, _fragmentFilename;

        GLuint _vertexID;
        GLuint _fragmentID;
        GLuint _programID;
    };
  }; /* namespace graphics */
}; /* namespace ng */
