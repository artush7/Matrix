# Parallel Matrix Library

A C++ matrix library supporting core linear algebra operations with built-in multi-threaded acceleration. The project includes a comprehensive unit test suite covering mathematical correctness, memory management, exception handling, and execution time benchmarks comparing sequential and parallel execution.

## Requirements

* **Compiler:** `clang++`(C++17 or newer) (`g++` is not supported)
* **Build System:** `make`
* **Dependencies:** Google Test (`gtest`)
* **OS:** POSIX (Linux, macOS, WSL)

## Build & Test

1. Clone the repository to your local machine, Run `git clone https://github.com/artush7/Matrix`.
2. Open a terminal and go to the project directory.
3. Run `make test` to compile and run all unit tests.
4. Run `make test_static` or `make test_dynamic` if you want to test with static or dynamic libraries.
5. Run `make clean` to remove build artifacts.

## Features

- **Parallel Processing:** Speeds up large matrix operations using 12 worker threads via POSIX Threads (`pthread`).
- **Core Operations:** Implements addition (`+`), subtraction (`-`), multiplication (`*`), and transposition (`transpose()`).
- **Generic & Memory Safe:** Templated `matrix<T>` supporting standard numeric types (`int`, `float`, `double`) with full Rule of Five support.
- **Exception Handling:** Validates matrix dimensions and throws `std::invalid_argument` on mismatches.
- **Testing & Libraries:** Includes a Google Test (`gtest`) suite with benchmarks (`<chrono>`) and supports static (`.a`) or dynamic (`.so`) builds.

  ## Known Issues

- This project was created for learning purposes, so it may contain imperfections.
- The thread count is hardcoded to 12 threads (you can manually change this value in the source code).
- Uses double pointers (`T**`) which is not optimal for CPU cache performance.
- Uses raw POSIX threads (`pthread`) instead of standard C++ threads.
