// ф-ция должна найти первое отрицательное число во второй половине вектора, а затем возвращает
// его индекс

#include <iterator>
#include <vector>
#include <algorithm>

int FindFirstNegativeInSecondHalf(const std::vector<int> &temperatures) {
    if (temperatures.empty()) {
        return -1;
    }

    auto it = std::find_if(temperatures.begin() + temperatures.size() / 2, temperatures.end(),
        [](int x) {
            return x < 0;
        });
        
    if (it == temperatures.end()) {
        return -1;
    }
    
    return std::distance(temperatures.begin(), it);
}