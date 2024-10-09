#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class TenacityFileParser {
public:
    static bool parse(const std::string& filepath, std::unordered_map<std::string, std::string>& data, std::vector<std::string>& authors);
    static bool parseFromString(const std::string& fileContents, std::unordered_map<std::string, std::string>& data, std::vector<std::string>& authors);
};
