// ф-ция должна вернуть вектор пар, используя string_view

#include <string_view>
#include <vector>

std::vector<std::pair<std::string_view, std::string_view>> ParseConfig(std::string_view config) {
    std::vector<std::pair<std::string_view, std::string_view>> result;
    
    while (!config.empty()) {
        auto semicolon = config.find(';');
        
        std::string_view segment;
        if (semicolon != std::string_view::npos) {
            segment = config.substr(0, semicolon);
            config.remove_prefix(semicolon + 1);
        } else {
            segment = config;
            config = {};
        }

        auto equal = config.find('=');
        if (equal == std::string_view::npos) {
            continue;
        }
        
        result.push_back({segment.substr(0, equal), segment.substr(equal+1)});

        config.remove_prefix(semicolon+1);
    }

    return result;
}