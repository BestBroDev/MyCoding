// нужно написать ф-цию, которая должна вернуть индекс последней команды,
// которая подходит под условие: команда начинается с prefix, а после prefix есть хотя бы один символ

#include <string>
#include <vector>

int FindLastValidIndex(const std::vector<std::string> &commands, const std::string &prefix) {
    int last_index = -1;

    auto lambda = [&prefix](std::string x) {
        size_t pos = x.find(':');
        
        if (pos != std::string::npos) {
            std::string word_before = x.substr(0, pos);
            std::string word_after = x.substr(pos + 1);

            return word_before == prefix && !word_after.empty();
        }

        return false;
    };
    
    for (int i = 0; i < commands.size(); ++i) {
        if (lambda(commands[i])) {
            last_index = i;
        } 
    }

    return last_index;
}