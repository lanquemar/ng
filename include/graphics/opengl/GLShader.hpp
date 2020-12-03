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
  };
};