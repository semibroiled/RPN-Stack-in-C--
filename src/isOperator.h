/**
 * This header file contains the isOperator function
 *
 * isOperator checks whether a character is one of 5 characters,
 * corresponding to a mathematical operation
 *
 * It is called in test_rpn_calculator.cpp and main.cpp
 */

#ifndef IS_OPERATOR
#define IS_OPERATOR

bool isOperator(char op)
{
    // Check for supported operations in Calculator Class
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

#endif