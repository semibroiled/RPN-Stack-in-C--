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
