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

void helpSheet()
{
    // Intro
    std::cout << std::endl;
    std::cout << "Some Instructions to help you along the tool" << std::endl;
    std::cout << std::endl;

    // Allowed Operators for Postfix Notation
    std::cout << "Type in Mathematical Expressions using:";
    std::cout << std::endl;

    std::cout << "-> '+' for Addition," << std::endl
              << "-> '-' for Subtraction," << std::endl
              << "-> '/' for Division," << std::endl
              << "-> '*' for Multplication," << std::endl
              << "-> '^' for Exponent";
    // * Add operations as you expand, check func_operator.h and rpn_calculator.cpp
    std::cout << std::endl;
    std::cout << std::endl;

    ///// TODO Need to add parser for inline syntax to rpn syntax
    // Two Modes of Operation
    std::cout << "The program runs either in RPN or Inline Mode";
    std::cout << std::endl;
    std::cout << "Type in Inline to switch to Inline mode,";
    std::cout << std::endl;
    std::cout << "or type in RPN to switch to RPN mode at any time";
    std::cout << std::endl;
    std::cout << std::endl;

    // Operators are postfix syntax
    std::cout << "Expressions have to be in RPN or Postfix Notation when in RPN Mode;";
    std::cout << std::endl;

    // Examples of inputs
    std::cout << "You would write an inline expression 5+3 in RPN Notation as 5 3 +";
    std::cout << std::endl;
    std::cout << std::endl;

    // Operators are inline syntax
    std::cout << "Expressions have to be in Inline Notation when in Inline Mode;";
    std::cout << std::endl;

    // Examples of inputs
    std::cout << "You would write an inline expression >> 5 + 3";
    std::cout << std::endl;
    std::cout << "Inline expressions are converted into RPN before evaluation";
    std::cout << std::endl;

    // Miscellaneous
    std::cout << "Note that the expression tokens have to be separated by a space";
    std::cout << std::endl;
    std::cout << std::endl;
}

#endif
