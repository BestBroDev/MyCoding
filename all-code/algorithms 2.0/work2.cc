// ф-ция должна удалить из вектора элементы меньшие или равные нулю
// и вернуть кол-во удалённых элементов

#include <vector>
#include <algorithm>

size_t RemoveInvalidTransactions(std::vector<long long> &amounts) {

    size_t orig_size = amounts.size();

    auto new_end = std::remove_if(amounts.begin(), amounts.end(), [](long long x) {
        return x <= 0;
    });

    amounts.erase(new_end, amounts.end());

    return orig_size - amounts.size();
}