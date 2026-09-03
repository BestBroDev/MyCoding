// ф-ция обрабатывает элемент и добавляет её в конце очереди

#include <queue>

std::vector<int> ProcessTasks(std::queue<int> &tasks, int max_rounds) {
    std::vector<int> result = {};
    result.reserve(max_rounds);

    if (tasks.empty()) {
        return result;
    }

    int copy = 0;
    for (int i = 0; i < max_rounds; ++i) {
        copy = tasks.front();
        result.push_back(copy);
        tasks.pop();
        tasks.push(copy);
    }

    return result;
}