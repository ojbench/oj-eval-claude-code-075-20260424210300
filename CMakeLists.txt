cmake_minimum_required(VERSION 3.10)
project(problem_075)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a minimal main.cpp for testing locally
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp "#include \"str.hpp\"\nint main() { return 0; }")
endif()

add_executable(code str.hpp main.cpp)

# Only add main.cpp to gitignore for local builds
set(SRC_FILES_TO_IGNORE
    main.cpp
)