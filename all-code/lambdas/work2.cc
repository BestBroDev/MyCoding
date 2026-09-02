// нужно написать ф-цию, которая должна сосчитать
// сколько элементов вектора подходят под условие

#include <vector>

size_t CountLargeWithdrawals(const std::vector<long long> &amounts, long long threshold) {
    if (threshold < 0) { // вместо проверки amounts.empty()
        threshold = 0;
    }
    
    size_t result = 0;

    auto lambda = [threshold](long long x) {
        return x < 0 && x <= -threshold; // неправильно прочитал условие; убрал std::abs()
    };

    for (auto a : amounts) {
        if (lambda(a)) {
            ++result;
        }
    }

    return result;
}