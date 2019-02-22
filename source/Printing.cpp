#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "../utilities/timer.h"



int main(int argc, char *argv[]) {
    std::ofstream output1("text/output1.txt", std::ofstream::out);
    std::ofstream output2("text/output2.txt", std::ofstream::out);
    Timer timer;
    double first, second;
    timer.start();
    for (int x{0}; x<1000000; ++x) {
        output1 << x << std::endl;
    }
    timer.stop();
    first = timer.getTime();
    timer.start();
    for (int x{0}; x<1000000; ++x) {
        output2 << x << '\n';
    }
    timer.stop();
    second = timer.getTime();
    std::cout << "Printing with std::endl: "<< first << std::endl;
    std::cout << "Printing with \\n: " << second << std::endl;
    output1.close();
    output2.close();
}