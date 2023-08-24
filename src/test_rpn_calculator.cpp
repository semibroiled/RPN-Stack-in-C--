#include "rpn_calculator.h" // ? This isn't getting imported properly from its own directory- temporary fix is putting in /src
#include "isOperator.h"
#include <iostream>
#include <cassert>
#include <sstream>

void runTests() {

    // Store test cases in string array
    std::string expressions[] = {
        "5 3 +", // 5+3=8
        "3 9 4 * +", // (4*9)+3=39
        "10 5 /", // 10/5=2
        "10 4 /" // 10/4=1.5
        //Add expressions to evaluate as neccessary
    };

    // Store answers to test cases in doubles array
    double expectResults[] = {8, 39, 2, 2.5};

    for (int i=0; i<(std::size(expectResults)); i++) {
        
        RPNStackCalculator tester;
        
        std::istringstream iss(expressions[i]);
        std::cout << expressions[i] <<" => ";
        std::string token;

        while (iss>>token) {
            if(isdigit(token[0])) {
                double operand = std::stoi(token);
                //std::cout << "Operand: " << operand << std::endl;
                tester.pushOperand(operand);
            } else if (isOperator(token[0])) {
                // If the token is an Operator, pop top 2 operands to compute 
                char curOperator = token[0];
                //std::cout << "Current Operator: " << curOperator << std::endl;
                tester.compute(curOperator);
            } else {
                std::cerr << "Invalid Token: " << token << std::endl;
                
            }
        };

    
        double result = tester.fetchResult();
        std::cout << result;
        assert(result == expectResults[i]);
        std::cout << " : TRUE (!)"<<std::endl;
    };

    std::cout << "All Tests Successfully Passed!" << std::endl;
}

int main() {
    runTests();

    return 0;
}

