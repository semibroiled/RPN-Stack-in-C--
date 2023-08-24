/**
 * This cpp file defines functions for the RPNStackcalculator class
 *
 * Performs rudimentary error handling and validates input
 */

#include "rpn_calculator.h"

// Call Class
RPNStackCalculator::RPNStackCalculator() {}

// Method function to push operands onto top of stack
void RPNStackCalculator::pushOperand(double operand)
{
    operandStack.push(operand);
}

// Compute the results when encountering an operator. At least two operands
// must be in the stack to carry out an operation
void RPNStackCalculator::compute(char op)
{
    if (operandStack.size() < 2)
    {
        throw std::runtime_error(
            "Stack doesn't hold enough operands to compute");
    }

    double operand2 = operandStack.top();
    operandStack.pop();
    double operand1 = operandStack.top();
    operandStack.pop();

    switch (op)
    {
    case '+':
        operandStack.push(operand1 + operand2);
        break;
    case '-':
        operandStack.push(operand1 - operand2);
        break;
    case '*':
        operandStack.push(operand1 * operand2);
        break;
    case '/':
        operandStack.push(operand1 / operand2);
        break;
    case '^':
        operandStack.push(std::pow(operand1, operand2));
        break;
    default:
        throw std::runtime_error("Illegal Operator");
    };
}

// Retrieve a result for an expression. Should be the last value
// left in the stack.
double RPNStackCalculator::fetchResult()
{
    if (operandStack.empty())
    {
        throw std::runtime_error("No results in Stack");
    }

    if (operandStack.size() > 1)
    {
        throw std::runtime_error("Stack has more than value. "
                                 "Expression must evaluate to  a single value. "
                                 "Try adding missing operators");
    }

    return operandStack.top();
}