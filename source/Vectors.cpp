#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../utilities/timer.h"
using std::cout;

unsigned int numOfCalls{0};

struct object {
	double x;
	double y;

	object(double x, double y)
		: x(x), y(y) {}

	object(const object &source)
		: x(source.x), y(source.y) {
		numOfCalls++;
	}
};

int main(int argc, char *argv[]) {

	Timer timer;
	cout << "\nemplace_back with object passing\n";
	timer.start();
	std::vector<object> vec1{};
	for(int x{0}; x<20; ++x) {
		vec1.emplace_back(object{1, 1});
	}
	timer.stop();
	cout << "Number of made copies:" << numOfCalls << "\n\n";

	numOfCalls=0;

	cout << "emplace_back with parameters passing \n";
	timer.start();
	std::vector<object> vec2{};
	for(int x{0}; x<20; ++x) {
		vec2.emplace_back(1, 1);
	}
	timer.stop();
	cout << "Number of made copies:" << numOfCalls << "\n\n";
}
