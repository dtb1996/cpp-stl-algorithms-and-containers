cmake_minimum_required(VERSION 3.16)

project(cpp_stl-algorithms-and-containers
    VERSION 1.0.0
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Place all executables in build/bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Define executable
add_executable(word_counter_app
    examples/main.cpp
    src/text_processing.cpp
    src/top_words.cpp
    src/word_counter.cpp
)

# Word Counter Tests
add_executable(word_counter_tests
    tests/word_counter_tests.cpp
    src/text_processing.cpp
    src/top_words.cpp
    src/word_counter.cpp
)

# Create an interface target for headers
add_library(project_headers INTERFACE)
target_include_directories(project_headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link to targets
target_link_libraries(word_counter_app PRIVATE project_headers)
target_link_libraries(word_counter_tests PRIVATE project_headers)

# Warnings (compiler-specific)
if (MSVC)
    target_compile_options(word_counter_app PRIVATE /W4 /WX)
    target_compile_options(word_counter_tests PRIVATE /W4 /WX)
else()
    target_compile_options(word_counter_app PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(word_counter_tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
