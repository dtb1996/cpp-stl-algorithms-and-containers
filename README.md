# cpp-stl-algorithms-and-containers

A focused C++ project demonstrating practical use of the C++ Standard Library, including algorithms, containers, iterators, and value-oriented design, using a word-counting application as the primary example.

This repository is intentionally engine-agnostic and avoids frameworks to highlight core language understanding.

## Goals

- Demonstrate idiomatic use of the C++ Standard Library
- Apply STL algorithms instead of manual loops where appropriate
- Use containers with clear ownership and lifetime semantics
- Write testable, modular, single-purpose components
- Practice separation of concerns (I/O vs logic)
- Produce portable, compiler-agnostic C++20 code

## Project Structure

```bash
cpp-stl-algorithms-and-containers/
├── include/
│   ├── text_processing.h
│   ├── top_words.h
│   └── word_counter.h
├── src/
│   ├── text_processing.cpp
│   ├── top_words.cpp
│   └── word_counter.cpp
├── examples/
│   └── main.cpp
├── tests/
│   └── word_counter_tests.cpp
├── sample.txt
├── CMakeLists.txt
├── .gitattributes
├── .gitignore
└── README.md
```

## Implemented Components

### Text Processing (`text_processing`)

Responsible for transforming raw text into normalized tokens.

#### Features

- Case normalization
- Punctuation stripping
- Whitespace handling
- Clean token extraction

#### STL Concepts

- `std::string`
- `std::transform`
- `std::isalpha`
- Iterator-based traversal
- Value-returning functions

### Word Counter (`word_counter`)

Counts word frequencies from a sequence of tokens.

#### Features

- Frequency tracking using associative containers
- Clear input/output boundaries
- No direct file or console I/O

#### STL Concepts

- `std::unordered_map`
- Range-based iteration
- Value semantics
- Separation of logic from presentation

### Top Words (`top_words`)

Extracts the most frequent words from a frequency map.

#### Features

- Configurable top-N selection
- Stable, deterministic output
- Efficient sorting logic

#### STL Concepts

- `std::vector`
- `std::partial_sort` / `std::sort`
- Custom comparison functions
- Algorithm-driven design

### Main Application (`examples/main.cpp`)

A small CLI application that wires the components together.

#### Responsibilities

- Parse command-line arguments
- Read input text file
- Invoke processing pipeline
- Display results

#### Design Notes

- Keeps business logic out of main
- Thin orchestration layer only
- Easy to extend or replace with another frontend

### Tests (`word_counter_tests`)

A lightweight test executable validating core logic.

#### What’s Tested

- Tokenization correctness
- Word frequency counting
- Top-N word selection
- Edge cases (empty input, small N)

#### Purpose

- Demonstrates testability of STL-heavy code
- Encourages logic without side effects
- No external test frameworks required

## Key Concepts Demonstrated

- STL algorithms over manual loops
- Appropriate container selection
- Deterministic, testable functions
- Header/source separation
- Namespaces for logical grouping
- Modern C++20 compilation practices
- Cross-platform builds using CMake

## Build Requirements

### Required

- **C++ compiler with C++20 support**
  - Windows: MSVC (Visual Studio Build Tools)
  - Linux: `g++` or `clang`
- **CMake 3.16 or newer**

## Installing CMake

### Windows

Download and install from: [CMake Download](https://cmake.org/download/)

Make sure **“Add CMake to PATH”** is enabled during installation.

Verify:

```bash
cmake --version
```

### Linux

```bash
sudo apt update
sudo apt install cmake build-essential
```

Verify:

```bash
cmake --version
```

## Build Instructions

1. Configure the project

   From the project root:

   ```bash
   cmake -S . -B build
   ```

2. Build

   ```bash
   cmake --build build
   ```

3. Run

   Windows

   ```bash
   build\bin\word_counter_app.exe \data\sample.txt 10
   ```

   Linux

   ```bash
   ./build/bin/word_counter_app data/sample.txt 10
   ```

## Running Tests

Windows:

```bash
build\bin\word_counter_tests.exe
```

Linux:

```bash
./build/bin/word_counter_tests
```
