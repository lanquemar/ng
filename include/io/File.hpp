#pragma once

#include <string>
#include <fstream>

#include "Buffer.hpp"

namespace ng
{
  namespace io
  {
    class File
    {
      public:
        enum mode
        {
          READ = 1 << 0,
          WRITE = 1 << 1,
          TEXT = 1 << 2,
          BINARY = 1 << 3
        };

        File();
        File(const std::string &);
        ~File();

        void open(int opts = READ | BINARY);
        void open(const std::string &, int opts = READ | BINARY);
        std::size_t size();
        void readAll(ng::io::Buffer &);

      private:
        void _open(int);

        std::string _filename;
        int _opts;
        std::fstream _file;
    };
  };
};