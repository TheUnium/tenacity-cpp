cmake_minimum_required(VERSION 3.20)
project(tenacity_library)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(tenacity STATIC
    src/Tenacity.cpp
    src/TenacityFileParser.cpp
)

target_include_directories(tenacity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
