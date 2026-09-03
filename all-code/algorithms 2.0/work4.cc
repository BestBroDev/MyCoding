// ф-ция должна удалить из вектора все дубликаты, сохраняя
// порядок первых вхождений

#include <set>
#include <vector>
#include <string>
#include <algorithm>

void RemoveDuplicatesKeepOrder(std::vector<std::string> &words) {
    std::set<std::string> unique;

    auto lambda = [&unique](std::string x) {
        return !unique.insert(x).second;
    };

    words.erase(
        remove_if(words.begin(), words.end(), lambda),
        words.end()
    );
}