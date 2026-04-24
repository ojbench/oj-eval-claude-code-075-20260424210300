cmake_minimum_required(VERSION 3.10)
project(problem_075)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code str.hpp)

# Create an empty main.cpp if it doesn't exist
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp "int main() { return 0; }")
endif()

target_sources(code PRIVATE main.cpp)