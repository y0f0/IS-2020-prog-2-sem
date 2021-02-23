cmake_minimum_required(VERSION 3.17)
project(homework2)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(homework2 main.cpp Polynomial.cpp Polynomial.h test_runner.h)