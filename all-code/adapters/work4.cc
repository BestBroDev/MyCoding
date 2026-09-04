// ф-ция, которая должна слить все очереди вектора в один отсортированный вектор

#include <vector>
#include <queue>

std::vector<int> MergeQueues(std::vector<std::queue<int>> &queues) {
    std::vector<int> result = {};
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
    std::greater<std::pair<int, int>>> min_elem = {};

    // проходимся по каждой очереди в векторе, добавляем в приоритетный вектор элементы очередей
    for (size_t i = 0; i < queues.size(); ++i) {
        if (!queues[i].empty()) {
            min_elem.push({queues[i].front(), i});
        }
    }

    // пока приор. вектор не пуст, добавляем в вовзр. вектор векторы в порядке возрастания, параллельно
    // удаляя очереди из queues
    while (!min_elem.empty()) {
        auto min = min_elem.top();
        min_elem.pop();

        int val = min.first;
        int index = min.second;

        result.push_back(val);

        queues[index].pop();

        if (!queues[index].empty()) {
            min_elem.push({queues[index].front(), index});
        }
    }

    return result;
}