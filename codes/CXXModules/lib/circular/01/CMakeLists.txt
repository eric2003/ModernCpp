cmake_minimum_required(VERSION 3.24...3.28)
project(testprj CXX)

message( STATUS "CMake_TEST_MODULE_COMPILATION_RULES=${CMake_TEST_MODULE_COMPILATION_RULES}")

add_library(circular STATIC)
target_sources(circular
  PUBLIC
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        circular-a.cppm
        circular-b.cppm)
target_compile_features(circular PUBLIC cxx_std_20)
