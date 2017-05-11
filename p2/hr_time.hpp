//hr_time.hpp and hr_time.cpp code originally written by David Bolton for the article "How do I do High Resolution Timing in C++ on Windows?"
//The article can be found here: http://cplus.about.com/od/howtodothingsi2/a/timing.htm

//#pragma once

#ifndef HR_TIME_HPP
#define HR_TIME_HPP

#include <chrono>
#include <ctime>
#include <ratio>
using namespace std::chrono;
//#include <windows.h>
/*
typedef unsigned long long LARGE_INTEGER;

typedef struct {
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
} stopWatch;
*/
class CStopWatch {

private:
  high_resolution_clock::time_point begin;
  high_resolution_clock::time_point end;

public:
  CStopWatch();
  void startTimer();
  void stopTimer();
  void reset();
  double getElapsedTime();
};

#endif
