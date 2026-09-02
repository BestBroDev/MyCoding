// написать ф-цию, которая для каждого числа в векторе
// создаёт лямбду-фильтр и которая затем сохраняет
// её в возвращаемом векторе

#include <functional>
#include <vector>
#include <iostream>

std::vector<std::function<bool(int)>> MakeThresholdFilters(const std::vector<int> &thresholds) {
    std::vector<std::function<bool(int)>> filters;

    for (size_t i = 0; i < thresholds.size(); ++i) {
        int cur = thresholds[i];
        filters.push_back([cur](int x) {
            return x >= cur;
        });
    }

    return filters;
}

int main() {
    auto filters = MakeThresholdFilters({0, 10, -5});

    std::cout << filters[0](5) << ' ' << filters[1](5) << ' ' << filters[2](5);
}