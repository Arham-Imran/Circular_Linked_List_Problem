#include <iostream>
#include "timing.hpp"

Timer::Timer() {}

void Timer::start()
{
    start_time = std::chrono::high_resolution_clock::now().time_since_epoch();
}

void Timer::end()
{
    end_time = std::chrono::high_resolution_clock::now().time_since_epoch();
    elapsed_seconds = end_time - start_time;
}

int64_t Timer::get_time()
{
    return elapsed_seconds.count();
}