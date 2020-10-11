#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

#define LOG(level) (ng::utils::Logger::getInstance().get(level))

enum LogLevel {ERROR, WARN, DEBUG};

namespace ng
{
  namespace utils
  {
    class Log
    {
      public:
        Log(LogLevel, std::ofstream &);
        ~Log();

        template<typename T>
        Log &operator<<(T const&msg)
        {
          std::cout << msg;
          _stream << msg;
          return (*this);
        }

        Log &operator<<(std::ostream & (*special)(std::ostream &))
        {
          special(std::cout);
          special(_stream);
          return (*this);
        }
      
      private:
        void _printTimestamp();

        LogLevel _level;
        std::ofstream &_stream;
    };

    class Logger
    {
      public:
        static Logger &getInstance()
        {
          static Logger instance;
          return (instance);
        }

        Log get(LogLevel);

      private:
        Logger();
        ~Logger();

        Logger(Logger const&);
        void operator=(Logger const&);

        std::ofstream _logFile;
    };
  };
};