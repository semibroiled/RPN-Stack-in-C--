/**
 * This header file contains the RPNStackCalculator Class
 *
 * RPNStackCalculator lets you declare an RPNStackCalculator object,
 * initializing with a private stack container of doubles.
 *
 * This declares 3 public methods
 *     pushOperand, compute and fetchResult
 *
 * This header file is called in
 *      rpn_calculator.cpp,
 *          where the functions are defined
 *      main.cpp,
 *          where it is instanced to run the program
 *      test_rpn_calculator.cpp,
 *          where an instance of it is used to test operations
 */

#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <stack>
#include <string>
#include <cmath>

class RPNStackCalculator
{
public:
    RPNStackCalculator();
    void pushOperand(double operand);
    void compute(char op);
    double fetchResult();

private:
    std::stack<double> operandStack;
};

#endif
