//hr_time.hpp and hr_time.cpp code originally written by David Bolton for the article "How do I do High Resolution Timing in C++ on Windows?"
//The article can be found here: http://cplus.about.com/od/howtodothingsi2/a/timing.htm

//#include <windows.h>

#ifndef hr_timer
#include "hr_time.hpp"
#define hr_timer
#endif

#include <chrono>
#include <ctime>
#include <ratio>

using namespace std::chrono;

/*
struct timespec timer_start() {
  struct timespec start_time;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
  return start_time;
}

long timer_end(struct timespec time_start()) {
    struct timespec end_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
    long diffInNanos = (end_time.tv_nsec - start_time.tv_nsec);
    return diffInNanos;
}
*/
CStopWatch::CStopWatch() {
        //begin = 0;
        //end = 0;
}

void CStopWatch::startTimer() {
        begin = high_resolution_clock::now();
}

void CStopWatch::stopTimer() {
	end = high_resolution_clock::now();
}


double CStopWatch::getElapsedTime() {
        duration<double> time_span = duration_cast<duration<double>>(end - begin);
        return time_span.count();
}

void CStopWatch::reset() {
        //begin = 0;
        //end = 0;
}

