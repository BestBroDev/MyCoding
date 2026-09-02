// нужно написать ф-цию, которая должна сосчитать
// сколько элементов вектора подходят под условие

#include <vector>
#include <cmath>

size_t CountLargeWithdrawals(const std::vector<long long> &amounts, long long threshold) {
    if (amounts.empty()) {
        return 0;
    }
    
    size_t result = 0;

    auto lambda = [threshold](long long x) {
        return x > 0 && std::abs(x) >= threshold;
    };

    for (auto a : amounts) {
        if (lambda(a)) {
            ++result;
        }
    }

    return result;
}