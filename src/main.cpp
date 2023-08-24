#include <iostream>
#include <sstream>
#include "rpn_calculator.h"
#include "isOperator.h"
#include "helpSheet.h"

/*
bool isOperator(char op) {
    // Check for supported operations in Calculator Class
    return op=='+' || op== '-' || op =='*' || op == '/' || op =='^';
}*/

int main() {

    std::string expression;
    std::cout << "Welcome to the RPN Stack Calculator Project!";
    std::cout << std::endl;
    std::cout << "This is an example implementation of a Calculator with Postfix Notation aka RPN implemented with a Stack in C++";
    std::cout << std::endl;

    bool run = true;
    while(run) {
        RPNStackCalculator calculator;
        
        std::cout << "Enter a valid postfix expression. Type exit to to quit. Type help to get additonal instructions";
        std::cout << std::endl;
        std::cout << ">>";

        std::getline(std::cin, expression);

        if ((expression == "e") || (expression == "exit") || (expression == "Exit"))  {
            run = false;
            continue;
        }

        if ((expression == "h") || (expression == "help") || (expression == "Help")) {
            
            helpSheet();
            /*
            std::cout << "Type in Mathematical Expressions with...";
            std::cout << std::endl;

            std::cout << "+ for Addition, - for Subtraction, / for Division, * for Multplication and ^ for Exponent";
            std::cout << std::endl;

            std::cout << "Expressions have to be in RPN or Postfix Notation, ie...";
            std::cout << std::endl;

            std::cout << "You would write an inline expression 5+3 in RPN Notation as 5 3 +";
            std::cout << std::endl;

            std::cout << "Note that the expression tokens have to be separated by a space";
            std::cout << std::endl;
            std::cout << std::endl; */ // ! Replace with a call function

            continue;
        }

        std::istringstream iss(expression);
        std::string token;

        while (iss>>token) {
            if(isdigit(token[0])) {
                double operand = std::stoi(token);
                calculator.pushOperand(operand);
            } else if (isOperator(token[0])) {
                // If the token is an Operator, pop top 2 operands to compute 
                char curOperator = token[0];
                calculator.compute(curOperator);
            } else {
                std::cout << "Invalid Token: " << token << std::endl;
                std::cout << "If the token is an Operator supported by class, add to isOperator functoin in main.cpp";
                std::cout << std::endl;
            }
        };

        try {
            double result = calculator.fetchResult();
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;

        };
    };

    return 0;
}

/*
#include <iostream>
#include <stack>
#include <sstream> //Parse string to numbers
#include <cmath>

using namespace std;

// Function to check if a character is an Operator
bool isOperator(char op) {
        return op=='+' || op== '-' || op =='*' || op == '/' || op =='^';
}

// Function to perform an operation based on a certain operator
int implOperation (double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
        //case '**': return pow(a,b);
        default: throw std::runtime_error("Illegal Operator"); 
    };
}
int main(){
    stack<int> operandStack {}; // Declare stack

    string expression {}; // Declare string var to store input
    cout << "Enter an expression in postfix format" << endl;
    cout << ">>";
    getline(cin, expression);

    istringstream iss(expression);
    string token;

    while (iss >> token) {

        // If token is a number, add as operands to stack
        if(isdigit(token[0])) {
            
            //cout << token[0] << endl;
            double operand = stoi(token);
            operandStack.push(operand);
        } else if(isOperator(token[0])) {
            // If the token is an Operator, pop top 2 operands to compute 
            
            //cout << token[0]<< sizeof(token[0]) <<endl;
            char curOperator = token[0];
            // Guard clause to check if there are enough Operands
            if (operandStack.size() < 2) {
                cerr << "Not enough valid operands to carry out operation." <<endl;
                return 1;
            }
                        
            double operand2 = operandStack.top();
            operandStack.pop();

            double operand1 = operandStack.top();
            operandStack.pop();

            double result = implOperation(operand1, operand2, curOperator);
            operandStack.push(result);
        } else {
            // If not a number or operator, our token is invalid
            cout << "Invalid Token: " << token <<endl;
            return 1;
        }
    }

    // After expression is evaluated, stack size should be the result
    if (operandStack.size() == 1) {
        cout << "Result: " << operandStack.top() << endl;
    } else {
        cout << "Expression evaluated to more than one operand left in stack." <<endl;
        return 1;
    }


    return 0;
};
*/