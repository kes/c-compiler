cmake_minimum_required(VERSION 3.16..3.24)
project(Compiler VERSION 1.0)
   
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED Yes)

                                                            
## we will be testing
include(CTest)

## libraries for the app
add_subdirectory(src/lexer)
add_subdirectory(src/util)

## testing --external is gtest
add_subdirectory(submods)
## the actual tests
add_subdirectory(tests)

## the app itself
add_executable(Compiler src/compiler.cpp)
target_include_directories(Compiler PUBLIC src/lexer)
target_link_libraries(Compiler PUBLIC lexer)
