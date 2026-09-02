// ф-ция, которая должна вернуть количество элементов вектора меньше 100

#include <vector>
#include <algorithm>

size_t CountFastResponses(const std::vector<int> &response_times_ms) {
    return std::count_if(response_times_ms.begin(), response_times_ms.end(), [](int x) {
        return x < 100;
    });
}