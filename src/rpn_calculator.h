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
