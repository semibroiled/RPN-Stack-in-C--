/**
 * This header file contains the helpSheet function
 * 
 * This calls forth a list of string literal instructions to the terminal
 * in main.cpp
 * 
 * This can be added upon to provide further instruction for use
*/

#ifndef HELP_SHEET
#define HELP_SHEET

void helpSheet () {
    // Intro
    std::cout << "Some Instructions to help you along the tool"<<std::endl;

    // Allowed Operators for Postfix Notation
    std::cout << "Type in Mathematical Expressions using:";
    std::cout << std::endl;

    std::cout   << "-> '+' for Addition," << std::endl 
                << "-> '-' for Subtraction," << std::endl 
                <<  "-> '/' for Division," << std::endl 
                <<  "-> '*' for Multplication," << std::endl 
                << "-> '^' for Exponent";
    // * Add operations as you expand, check isOperator.h and rpn_calculator.cpp
    std::cout << std::endl;

    // TODO Need to add parser for inline syntax to rpn syntax
    // Operators are postfix syntax
    std::cout << "Expressions have to be in RPN or Postfix Notation;";
    std::cout << std::endl;

    // Examples of inputs
    std::cout << 
    "You would write an inline expression 5+3 in RPN Notation as 5 3 +";
    std::cout << std::endl;

    // Miscellaneous 
    std::cout << 
    "Note that the expression tokens have to be separated by a space";
    std::cout << std::endl;
    std::cout << std::endl;
}

#endif

