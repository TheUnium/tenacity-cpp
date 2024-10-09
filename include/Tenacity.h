#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Tenacity {
public:
    bool loadFile(const std::string& filepath);
    bool loadFromString(const std::string& fileContents);
    std::string get(const std::string& key) const;
    std::vector<std::string> getAuthors() const;
    bool isValid() const;

private:
    std::unordered_map<std::string, std::string> data;
    std::vector<std::string> authors;
    std::vector<std::string> requiredFields = {"name", "version", "license"};

    void validateFile();
};
