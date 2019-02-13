#include "timer.h"

void Timer::start() {
    t1 = std::chrono::steady_clock::now();
    t1Measured = true;
}

void Timer::stop() {
    if (!t1Measured) {
        std::cerr << "Starting time not measured!\n";
        return;
    } else {
        t1Measured = false;
    }
    t2 = std::chrono::steady_clock::now();
    readyToPrint = true;
    estimatedTime = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
}

void Timer::print() {
    if (!readyToPrint && t1Measured) {
        std::cerr << "Not ready to print!\n";
        return;
    } else {
        t1Measured = false;
    }
    std::cout << std::fixed << "Estimated time: " << estimatedTime.count() << "s \n";
}

double Timer::getTime() {
    if (!readyToPrint && t1Measured) {
        std::cerr << "Time not ready to obtain!\n";
        return -1;
    } else {
        t1Measured = false;
    }
    
    return estimatedTime.count();
}