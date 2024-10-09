# tenacity-cpp 
pretty useless for most people, but sort of useful for me. mainly used for my project manager thingy.

## tenacity file format :
```
name "project name"
description "project description"
version "project version"
license "whatever license name"
author "author 1" "author 2"
```

## how to use tenacity-cpp (example)
its pretty simple so it doesnt really need that much explanation 👍
```cpp
#include "Tenacity.h"
#include <iostream>

int main() {
    Tenacity tenacity;
    
    if (!tenacity.loadFile('./project.tenacity')) {
        std::cerr << "failed to load proj file :(" << std::endl;
        return 1;
    }
    
    if (!tenacity.isValid()) {
        std::cerr << "project file is missing required keys." << std::endl;
        return 1;
    }
    
    std::cout << "proj name : " << tenacity.get("name") << std::endl;
    std::cout << "proj description : " << tenacity.get("description") << std::endl;
    std::cout << "proj version : " << tenacity.get("version") << std::endl;
    std::cout << "proj license : " << tenacity.get("license") << std::endl;

    auto authors = tenacity.getAuthors();
    std::cout << "proj authors : ";
    for (const auto& author : authors) {
        std::cout << author << ", ";
    }
    
    std::cout << std::endl;
    return 0;
}
```