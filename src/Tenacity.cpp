#include "Tenacity.h"
#include "TenacityFileParser.h"
#include <algorithm>
#include <iostream>

bool Tenacity::loadFile(const std::string& filepath) {
    if (!TenacityFileParser::parse(filepath, data, authors)) { std::cerr << "couldnt load/parse file : " << filepath << std::endl; return false; }
    validateFile();
    return true;
}

bool Tenacity::loadFromString(const std::string& fileContents) {
    if (!TenacityFileParser::parseFromString(fileContents, data, authors)) { std::cerr << "couldnt load/parse string" << std::endl; return false; }
    validateFile();
    return true;
}

void Tenacity::validateFile() {
    for (const auto& field : requiredFields) {
        if (data.find(field) == data.end()) { std::cerr << "missing field : " << field << std::endl; }
    }
}

std::string Tenacity::get(const std::string& key) const {
    if (data.find(key) != data.end()) { return data.find(key)->second; }
    return "";
}

std::vector<std::string> Tenacity::getAuthors() const {
    return authors;
}

bool Tenacity::isValid() const {
    return std::all_of(requiredFields.begin(), requiredFields.end(), [&](const auto& field) {
        return data.find(field) != data.end();
    });
}
