cmake_minimum_required(VERSION 3.24...3.28)
project(cxx_modules_simple CXX)

add_executable(simple)
target_sources(simple
  PRIVATE
    main.cxx
  PRIVATE
    FILE_SET CXX_MODULES
      BASE_DIRS
        "${CMAKE_CURRENT_SOURCE_DIR}"
      FILES
        importable.cxx)
target_compile_features(simple PUBLIC cxx_std_20)

add_test(NAME simple COMMAND simple)
