cmake_minimum_required(VERSION 3.16)
project(RPNStackCalculator)

set(CMAKE_CXX_STANDARD 23)

# Add main executable
add_executable(rpn_calculator src/main.cpp src/rpn_calculator.cpp)

target_include_directories(rpn_calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Add Testing
enable_testing()

add_executable(test_calculator src/test_rpn_calculator.cpp src/rpn_calculator.cpp)

add_test(NAME CalculatorTest COMMAND test_calculator)

