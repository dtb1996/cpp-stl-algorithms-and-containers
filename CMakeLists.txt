cmake_minimum_required(VERSION 3.16)

project(cpp_stl-algorithms-and-containers
    VERSION 1.0.0
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define executable
add_executable(cpp_stl-algorithms-and-containers
    examples/main.cpp
    src/text_processing.cpp
    src/top_words.cpp
    src/word_counter.cpp
)

# Public include directory
target_include_directories(cpp_stl-algorithms-and-containers
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Warnings (compiler-specific)
if (MSVC)
    target_compile_options(cpp_stl-algorithms-and-containers PRIVATE /W4 /WX)
else()
    target_compile_options(cpp_stl-algorithms-and-containers PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
