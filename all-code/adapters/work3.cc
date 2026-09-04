// ф-ция должна вернуть вектор пар, используя string_view

#include <string_view>
#include <vector>

std::vector<std::pair<std::string_view, std::string_view>> ParseConfig(std::string_view config) {
    std::vector<std::pair<std::string_view, std::string_view>> result;
    
    while (!config.empty()) {
        size_t semicolon = config.find(';');
        
        std::string_view segment = config.substr(0, semicolon);

        size_t equal = segment.find('=');
        if (equal != std::string_view::npos) {
            result.emplace_back(segment.substr(0, equal), segment.substr(equal+1));
        }

        if (semicolon == std::string_view::npos) {
            break;
        }

        config.remove_prefix(semicolon+1);
    }

    return result;
}