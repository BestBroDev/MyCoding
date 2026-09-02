// задание сделать лямбду, 
// которая проверяет каждое число: находится ли оно между -50 и 150

#include <vector>
#include <iostream>

int main() {
    std::vector<int> readings = {-51, -50, -5, 0, 150, 151};

    auto lambda = [](int reading) {
        return reading > -50 && reading < 150;
    };

    bool first = true;
    for (auto r : readings) {
        if (!first) {
            std::cout << ' ';
        }
        if (lambda(r)) {
            std::cout << r;
        }
        first = false;
    }

    return 0;
}