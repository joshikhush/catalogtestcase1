
# C++ Gaussian Elimination with JSON Input

This repository contains a C++ program that uses Gaussian Elimination to solve a system of linear equations with input data provided in a JSON file. The program also includes a custom base conversion function and demonstrates how to handle JSON data using the `nlohmann/json` library.

## Prerequisites

1. **C++ Compiler**: Ensure you have a C++ compiler installed. You can use GCC, Clang, or Visual Studio.
2. **JSON Library**: This project uses the `nlohmann/json` library. You need to have this library available to compile the code.

## Setup Instructions

### 1. Install C++ Compiler

   - **On Linux or macOS**: You can usually install GCC or Clang via your package manager.
   - **On Windows**: You can use MinGW or Visual Studio.

### 2. Create the Input JSON File

   - Create a file named `input.json` in the same directory as the source code. The JSON file should follow the format expected by the program.

### 3. Ensure Dependencies

   - Download the `nlohmann/json` header file from [nlohmann/json GitHub](https://github.com/nlohmann/json) and place it in your project directory or install it using a package manager.

### 4. Compile the Code

   - **Using Command Line**:
     - For GCC or Clang:
       ```sh
       g++ -o my_program main.cpp
       ```
     - For Windows with MinGW:
       ```sh
       g++ -o my_program.exe main.cpp
       ```
     - If you need to include the JSON library explicitly:
       ```sh
       g++ -I/path/to/json/include -o my_program main.cpp
       ```

   - **Using CMake** (if you have a `CMakeLists.txt` file):
     - Create a `CMakeLists.txt` file with the following content:
       ```cmake
       cmake_minimum_required(VERSION 3.10)
       project(MyProject)

       set(CMAKE_CXX_STANDARD 17)

       include_directories(/path/to/json/include)
       add_executable(my_program main.cpp)
       ```
     - Run the following commands:
       ```sh
       mkdir build
       cd build
       cmake ..
       make
       ```

### 5. Run the Program

   - **On Unix-like Systems**:
     ```sh
     ./my_program
     ```
   - **On Windows**:
     ```sh
     my_program.exe
     ```

### 6. Verify Output

   - Check the console output to ensure it matches your expectations.

## Troubleshooting

- **Compiler Errors**: Ensure all required libraries and dependencies are correctly linked.
- **File Paths**: Verify the path to `input.json` and make sure it’s accessible.
- **Library Version**: Ensure you’re using a compatible version of the `nlohmann/json` library if you encounter issues.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
