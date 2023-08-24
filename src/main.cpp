#include <iostream>
#include <sstream>
#include "rpn_calculator.h"
#include "isOperator.h"
#include "helpSheet.h"

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
                std::cout << "If the token is an Operator supported by RPNStackCalculator Class, add to isOperator function in isOperator.h"; 
                // ! Change to cerr terminal
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