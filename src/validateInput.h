/**
 * This header file contains a function to check for alphabets in a string
 * which are not one of the allowed characters
 *
 * Calles as Guard Clause in Main before Running Loop with Expression
 */

#ifndef VALIDATE_NUM
#define VALIDATE_NUM

#include <string>
#include "func_operator.h"

bool alphaInString(std::string token)
{
    for (char c : token)
    {
        // Check to see if alphabet in expression
        if ((!isdigit(c)) && (!isParenthese(c)) &&
            (!isOperator(c)) && (std::isalnum(c)))
        {
            return true;
        }
    }
    return false;
}
#endif