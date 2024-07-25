#ifndef __Timing__
#define __Timing__
#include <iostream>
#include <chrono>

class Timer
{
    private:
    //std::chrono::time_point<std::chrono::system_clock> start_time, end_time;
    std::chrono::duration<int64_t, std::nano> start_time, end_time;
    std::chrono::nanoseconds elapsed_seconds;
    public:
    Timer();
    void start();
    void end();
    int64_t get_time();
};

#endif