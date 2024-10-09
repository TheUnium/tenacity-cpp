#include "TenacityFileParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

bool TenacityFileParser::parse(const std::string& filepath, std::unordered_map<std::string, std::string>& data, std::vector<std::string>& authors) {
    std::ifstream file(filepath);
    if (!file.is_open()) { std::cerr << "cant open file : " << filepath << std::endl; return false; }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') { continue; }

        std::istringstream iss(line);
        std::string key;
        std::getline(iss, key, ' ');

        if (key == "author") {
            std::string author;
            while (std::getline(iss, author, '"')) {
                if (!author.empty() && author != " ") {
                    authors.push_back(author);
                    if (iss.peek() == '"') { iss.get(); }
                }
            }
        } else {
            std::string value;
            if (std::getline(iss, value)) {
                if (value.size() > 2 && value.front() == '"' && value.back() == '"') { value = value.substr(1, value.size() - 2); }
                data[key] = value;
            } else {
                std::cerr << "cant parsing line : " << line << std::endl;
            }
        }
    }
    file.close();
    return true;
}

bool TenacityFileParser::parseFromString(const std::string& fileContents, std::unordered_map<std::string, std::string>& data, std::vector<std::string>& authors) {
    std::istringstream stream(fileContents);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.empty() || line[0] == '#') { continue; }

        std::istringstream iss(line);
        std::string key;
        std::getline(iss, key, ' ');

        if (key == "author") {
            std::string author;
            while (std::getline(iss, author, '"')) {
                if (!author.empty() && author != " ") {
                    authors.push_back(author);
                    if (iss.peek() == '"') { iss.get(); }
                }
            }
        } else {
            std::string value;
            if (std::getline(iss, value)) {
                if (value.size() > 2 && value.front() == '"' && value.back() == '"') { value = value.substr(1, value.size() - 2); }
                data[key] = value;
            } else {
                std::cerr << "cant parsing line : " << line << std::endl;
            }
        }
    }
    return true;
}

