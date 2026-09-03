// ф-ция должна вернуть кол-во элементов в диапозоне [low, high]

#include <iterator>
#include <vector>
#include <algorithm>

size_t CountInRange(const std::vector<int> &sorted_prices, int low, int high) {
    auto it1 = std::lower_bound(sorted_prices.begin(), sorted_prices.end(), low);
    auto it2 = std::upper_bound(sorted_prices.begin(), sorted_prices.end(), high);

    return static_cast<size_t>(std::distance(it1, it2));
}