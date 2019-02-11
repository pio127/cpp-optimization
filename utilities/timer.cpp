#include "timer.h"

void Timer::start() {
    t1 = std::chrono::steady_clock::now();
    t1Measured = true;
}

void Timer::stop() {
    if (t1Measured == false){
        std::cout << "Starting time not measured!\n";
        return;
    } else {
        t1Measured = false;
    }
    t2 = std::chrono::steady_clock::now();
    auto estimatedTime{std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1)};
    std::cout <<std::fixed <<"Estimated time: " << estimatedTime.count() << "s \n";
}