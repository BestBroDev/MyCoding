// ф-ция, проверяющая является ли строка палиндромом
// +ф-ция, которая сортирует вектор по убыванию

#include <vector>
#include <string>
#include <algorithm>

bool IsPalindrome(std::string word) {
    auto lambda = [](std::string &x) {
        std::string orig = x;
        std::reverse(orig.begin(), orig.end());
        return x == orig;
    };

    return lambda(word);
}

void SortDescending(std::vector<int> &data) {
    std::sort(data.begin(), data.end(), [](int a, int b) {
        return a > b;
    });
}