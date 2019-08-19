#include <vector>
#include <string>
#include "timer.h"

class Object{
public:
    Object(const std::vector<std::string> &array)
            : _array(array) {}
private:
    std::vector<std::string> _array;
};

class ObjectWithMove {
public:
    ObjectWithMove(std::vector<std::string> array)
            : _array(std::move(array)) {}
private:
    std::vector<std::string> _array;
};

int main() {
    Timer timer;
    std::vector<std::string> bigArray;
    for(int x = 0; x < 10000000 ; ++x) {
        bigArray.emplace_back(std::to_string(x));
    }
    timer.start();
    Object object{bigArray};
    timer.stop();
    timer.print();

    timer.start();
    ObjectWithMove objectWithMove{bigArray};
    timer.stop();
    timer.print();
}