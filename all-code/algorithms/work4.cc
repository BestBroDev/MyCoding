// ф-ция должна вернуть вектор индексов, на которых
// элемент value встречается в векторе data

#include <vector>
#include <algorithm>

std::vector<size_t> FindAllPositions(const std::vector<int> &data, int value) {
    std::vector<size_t> result;

    for (auto it = std::find(data.begin(), data.end(), value);
    it != data.end(); it = std::find(std::next(it), data.end(), value)) {
        result.push_back(std::distance(data.begin(), it));
    }

    return result;
}