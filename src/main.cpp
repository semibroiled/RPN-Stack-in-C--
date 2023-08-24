/**
 * This main.cpp is the main endpoint for our calculator program
 * 
 * Calculate expressions in postfix syntax, implement rudimentary CLI 
 * functionality and add error handling
 * 
 * TODO Need to add parser to convert inline input to rpn 
 * 
*/
#include <iostream>
#include <sstream>
#include "rpn_calculator.h"
#include "isOperator.h"
#include "helpSheet.h"

int main() {

    // Introducing the Program
    std::cout << "Welcome to the RPN Stack Calculator Project!";
    std::cout << std::endl;
    std::cout << 
    "This is an example implementation of a Calculator with Postfix Notation, "
    "also known as RPN implemented with a Stack in C++";
    std::cout << std::endl;

    // Declare string variable that will contain the expression
    std::string expression;
    
    // Boolean Switch to run the calculator in loop
    bool run = true;

    //Calculator runs in this loop, adds basic CLI functionality
    while(run) {
        // Declare RPNStackCalculator instance, resets stack on each iteration
        RPNStackCalculator calculator;
        
        // Prompt for user input
        std::cout << 
        "Enter a valid postfix expression. " 
        "Type exit or e to to quit. " 
        "Type help or h to get additonal instructions";
        std::cout << std::endl;
        std::cout << ">>";
        
        // Get userinput line into expression
        std::getline(std::cin, expression);

        // Guard Clause for quitting application, flip switch to run is false
        if ((expression == "e") || (expression == "exit") || (expression == "Exit"))  {
            run = false;
            continue;
        }

        // Guard Clause for calling help.
        if ((expression == "h") || (expression == "help") || (expression == "Help")) {
            helpSheet();
            continue;
        }

        // Run expression through instance of iss
        std::istringstream iss(expression);

        // Initialize string to tokenize expression through iss
        std::string token;

        // Tokenize iss
        while (iss>>token) {
            if(isdigit(token[0])) {
                // Check if value numerical, push to stack
                double operand = std::stoi(token);
                calculator.pushOperand(operand);
            } else if (isOperator(token[0])) {
                // Check if operator, pop top 2 operands to compute 
                char curOperator = token[0];
                calculator.compute(curOperator);
            } else {
                // Parse for invalid inputs eg: operators not supported
                // or alphabets 
                std::cerr << "Invalid Token: " << token << std::endl;
                std::cerr << "If the token is an Operator supported by " 
                "RPNStackCalculator Class, add to isOperator function "
                "in isOperator.h"; 
                std::cout << std::endl;
            }
        };

        // Retrieve result after expression is strum through
        try {
            double result = calculator.fetchResult();
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;

        };
    };

    return 0;
}