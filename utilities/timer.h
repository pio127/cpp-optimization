#ifndef ESTIMATE_TIME
#define ESTIMATE_TIME

#include <chrono>
#include <iostream>
#include <iomanip>

using std::chrono::steady_clock;
using std::chrono::duration;


class Timer
{
private:
    steady_clock::time_point t1;
    steady_clock::time_point t2;
    duration<double> estimatedTime;
    bool t1Measured;
    bool readyToPrint;
public:
    void start();
    void stop();
    void print();
    double getTime();
};
#endif // ESTIMATE_TIME

