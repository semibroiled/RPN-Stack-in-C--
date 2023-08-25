
/**
 * This header file contains a function that carries our the Stunting Yard
 * Algorithm on Inline Expressions to convert it to a  RPN or Postfix Expression
 *
 * The Postfix Expressions is subsequently evaluated
 *
 * This function is only implemented in main.cpp if the mode is set to Inline
 */
#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include "func_operator.h"
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>

// * Function to Convert an Inline String Expression to RPN Format
std::string infixToPostfix(std::string expression)
{
    // * Employ Stunting Yard Algoirthm
    // Empty Stack to store operators
    std::stack<char> operators;

    // Empty String to store the operand expression
    std::string postfix_operands;

    // Instantiate expression into string stream
    std::istringstream iss(expression);
    std::string token;

    // Iterate over Inline Expression
    while (iss >> token)
    {
        ////std::cout << "Character: " << token[0] << " : " << token << std::endl;
        ////std::cout << "State of expressions: " << postfix_operands << std::endl;

        // Contextualize Token at 0 index as c
        char c = token[0];

        // Handle Numerical Values
        // ! isdigit checks for integers and not doubles
        // * check for integer in full token. Handle as double later
        // * or if in form .1241 with 0 omitted
        ///// TODO: implement you own function to check for doubles
        if ((std::isdigit(c)) || (c == '.'))
        {
            postfix_operands += token + " "; // Append Numerics to String
        }

        // Handle Operators
        if (isOperator(c))
        {
            // If Operator Stack not empty, and not an opening bracket
            // in top level, check for precedence and assign operators
            // to postfix operand expression
            while ((!operators.empty()) &&
                   operators.top() != '(' &&
                   operatorPrecedence(c) <= operatorPrecedence(operators.top()))
            {
                postfix_operands += operators.top();
                postfix_operands += " ";
                operators.pop();
            }

            // By Default, push operators to stack
            operators.push(c);
        }

        // Hanlde Parenthese
        if (isParenthese(c))
        {
            if (c == '(')
            {
                operators.push(c); // Push Opening Paranthesis as operator
            }
            else if (c == ')')
            {
                // For closing Parenthesis, push operators to expression
                // until we encounter the opening bracket in stack
                while ((!operators.empty()) && (operators.top() != '('))
                {
                    postfix_operands += operators.top();
                    postfix_operands += " ";
                    operators.pop();
                }
                if ((!operators.empty()) && (operators.top() == '('))
                {
                    operators.pop(); // Discard opening Paranthesis
                }
            }
        }
    }

    // For the rest of operators in stack, assign in FILO sequence
    while (!operators.empty())
    {
        postfix_operands += operators.top();
        postfix_operands += " ";
        operators.pop();
    }
    ////std::cout << "State of expressions: " << postfix_operands << std::endl;
    return postfix_operands;
}

#endif