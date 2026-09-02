// ф-ция должна вернуть индекс "первой" строки в векторе,
// содержит подстроку "ERROR"

#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

int FindFirstErrorIndex(const std::vector<std::string> &logs) {
    if (logs.empty()) {
        return -1;
    }

    auto it = std::find_if(logs.begin(), logs.end(), [](std::string x) {
        return x.find("ERROR") != std::string::npos;
    });

    if (it == logs.end()) {
        return -1;
    }

    return std::distance(logs.begin(), it);
}