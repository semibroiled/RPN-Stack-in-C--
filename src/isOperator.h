#ifndef IS_OPERATOR
#define IS_OPERATOR

bool isOperator(char op) {
    // Check for supported operations in Calculator Class
    return op=='+' || op== '-' || op =='*' || op == '/' || op =='^';
}

#endif