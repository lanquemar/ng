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

#include "utils/Logger.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>

std::chrono::high_resolution_clock::time_point start =
  std::chrono::high_resolution_clock::now();

const char *prefixes[] = {"ERROR", "WARN ", "DEBUG"};

namespace ng
{
  namespace utils
  {
    Log::Log(LogLevel level, std::ofstream &stream) :
      _level(level), _stream(stream)
    {
      _printTimestamp();
      std::cout << prefixes[_level] << " ";
      _stream << prefixes[_level] << " ";
    }

    Log::~Log()
    {
    }

    void Log::_printTimestamp()
    {
      std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();

      std::chrono::hours elapsed_hours =
        std::chrono::duration_cast<std::chrono::hours>(end - start);
      std::chrono::minutes elapsed_minutes =
        std::chrono::duration_cast<std::chrono::minutes>(end - start);
      std::chrono::seconds elapsed_seconds =
        std::chrono::duration_cast<std::chrono::seconds>(end - start);
      std::chrono::milliseconds elapsed_milliseconds =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

      std::cout <<
        std::setw(2) << std::setfill('0') << elapsed_hours.count() << "." <<
        std::setw(2) << (elapsed_minutes.count() % 60) << "." <<
        std::setw(2) << (elapsed_seconds.count() % 60) << "." <<
        std::setw(4) << (elapsed_milliseconds.count() % 1000) << " ";
      _stream <<
        std::setw(2) << std::setfill('0') << elapsed_hours.count() << "." <<
        std::setw(2) << (elapsed_minutes.count() % 60) << "." <<
        std::setw(2) << (elapsed_seconds.count() % 60) << "." <<
        std::setw(4) << (elapsed_milliseconds.count() % 1000) << " ";
    }

    Logger::Logger()
    {
      char buff[64];

      std::time_t now = std::time(NULL);
      std::strftime(buff, 64, "%F_%H-%M-%S.log", std::localtime(&now));

      _logFile.open(buff, std::ofstream::out | std::ofstream::app);
      if (!_logFile.is_open())
        std::cerr << "Cannot open file " << buff << std::endl;
    }

    Logger::~Logger()
    {
      _logFile.flush();
      _logFile.close();
    }

    Log Logger::get(LogLevel level)
    {
      return (Log(level, _logFile));
    }
  }; /* namespace utils */
}; /* namespace ng */
