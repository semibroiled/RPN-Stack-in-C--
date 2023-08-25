/**
 * This main.cpp is the main endpoint for our calculator program
 *
 * Calculate expressions in postfix syntax, implement rudimentary CLI
 * functionality and add error handling
 *
 * //TODO Need to add parser to convert inline input to rpn
 * * Update: Added Modes for parsing Inline to Postfix/RPN
 *
 * Main Operates in two modes, Inline or Postfix
 *
 * In Inline mode, the expression is converted to postfix notation
 * before being evaluated
 *
 * In Postfix mode, the expression is evaluated as is
 */
#include <iostream>
#include <sstream>
#include <cctype>
#include "rpn_calculator.h"
#include "func_operator.h"
#include "helpSheet.h"
#include "infixToPostfix.h"
#include "validateInput.h"

int main()
{
    // Introducing the Program
    std::cout << std::endl;
    std::cout << "Welcome to the RPN Stack Calculator Project!";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "This is an example implementation of a "
                 "Calculator with Postfix Notation,";
    std::cout << std::endl;
    std::cout << "also known as RPN implemented with a Stack in C++";
    std::cout << std::endl;
    std::cout << std::endl;

    // Declare string variable that will contain the expression
    std::string expression;

    // Boolean Switch to run the calculator in loop
    bool run = true;

    // TODO: Add functionality to parse infix to postfix
    // * Mode of Operation: Infix or postfix/rpn
    // * RPN by default
    // Define a working mode: in RPN or Inline
    std::string mode = "RPN";

    // Calculator runs in this loop, adds basic CLI functionality
    while (run)
    {
        // Declare RPNStackCalculator instance, resets stack on each iteration
        RPNStackCalculator calculator;

        // Prompt for user input
        std::cout << "Enter a valid expression. "
                  << "Current Mode: " << mode << std::endl;

        std::cout << "Type exit or e to to quit. "
                     "Type help or h to get additonal instructions.";
        std::cout << std::endl;
        std::cout << ">>";

        // Get userinput line into expression
        std::getline(std::cin, expression);

        // Guard Clause for quitting application, flip switch to run is false
        if ((expression == "e") || (expression == "q") ||
            (expression == "exit") || (expression == "Exit"))
        {
            run = false;
            continue;
        }

        // Guard Clause for calling help.
        if ((expression == "h") || (expression == "help") || (expression == "Help"))
        {
            helpSheet();
            continue;
        }

        // Guard Clause for mode changes
        // * RPN/Postfix Mode Change
        if ((expression == "post") || (expression == "rpn") ||
            (expression == "RPN") || (expression == "postfix"))
        {
            mode = "RPN";
            continue;
        }
        // * Inline Mode Change
        if ((expression == "inline") || (expression == "in"))
        {
            mode = "Inline";
            continue;
        }

        // Guard Close for letters in input
        if (alphaInString(expression))
        {
            std::cerr << "Error: Alphabets in expression" << std::endl;
            continue;
        }

        ///// TODO:  to parse infix to postfix.
        ///// ! Band Aid fix -> streamline to switch cases for better use
        ///// TODO: should return expression as postfix if in inline mode
        // If Mode is Inline, convert expression to Postfix
        if (mode == "Inline")
        {
            std::cout << ">> " << expression << " ==> ";
            try
            {
                // Parse, Change expression to postfix
                expression = infixToPostfix(expression);
                std::cout << expression << std::endl;
            }
            catch (const std::exception &ex)
            {
                // ! Is error being caught as such?
                // ? Can't get to run this edge case. Don't fix something not broken
                std::cerr << "Illegal Expression: " << ex.what() << std::endl;
            }
        }

        // * This section is based off of RPN/Postfix Notation from
        // * previous version
        // Run expression through instance of iss
        std::istringstream iss(expression);

        // Initialize string to tokenize expression through iss
        std::string token;

        // Tokenize iss
        while (iss >> token)
        {
            if (isdigit(token[0]))
            {
                // Check if value numerical, push to stack
                double operand = std::stod(token);
                calculator.pushOperand(operand);
            }
            else if (isOperator(token[0]))
            {
                // Check if operator, pop top 2 operands to compute
                char curOperator = token[0];
                calculator.compute(curOperator);
            }
            else
            {
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
        try
        {
            double result = calculator.fetchResult();
            std::cout << ">> Result: " << result << std::endl;
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error: " << ex.what() << std::endl;
        };
    };

    return 0;
}