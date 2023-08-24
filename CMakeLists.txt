cmake_minimum_required(VERSION 3.16)
project(RPNStackCalculator)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpn_calculator src/main.cpp src/rpn_calculator.cpp)

target_include_directories(rpn_calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Testing
enable_testing()

add_executable(test_calculator test/test_rpn_calculator.cpp src/rpn_calculator.cpp)

add_test(NAME CalculatorTest COMMAND test_calculator)

