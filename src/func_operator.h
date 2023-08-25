/**
 * This header file contains the isOperator function
 *
 * isOperator checks whether a character is one of 5 characters,
 * corresponding to a mathematical operation
 *
 * It is called in test_rpn_calculator.cpp and main.cpp
 */

#ifndef OPERATOR_COLL
#define OPERATOR_COLL

// Identify Operators
bool isOperator(char op)
{
    // Check for supported operations in Calculator Class
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

// Set Operator Precedence
int operatorPrecedence(char op)
{
    switch (op)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Identify Paranthese
bool isParenthese(char c)
{
    return ((c == ')') || (c == '('));
}

#endif