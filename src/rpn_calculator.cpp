#include "rpn_calculator.h"


RPNStackCalculator::RPNStackCalculator() {}

void RPNStackCalculator::pushOperand(double operand) {
    operandStack.push(operand);
}

void RPNStackCalculator::compute(char op) {
    if (operandStack.size() <2) {
        throw std::runtime_error("Stack doesn't hold enough operands to compute");
    }

    double operand2 = operandStack.top();
    operandStack.pop();
    double operand1 = operandStack.top();
    operandStack.pop();

    switch (op) {
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
        //case '**': return pow(a,b);
        default: throw std::runtime_error("Illegal Operator"); 
    };
}

double RPNStackCalculator::fetchResult(){
    if (operandStack.empty()) {
        throw std::runtime_error("No results in Stack");
    }

    if (operandStack.size()>1) {
        throw std::runtime_error("Stack has more than value. Expression must evaluate to  a single value. Try adding missing operators");
    }

    return operandStack.top();
}