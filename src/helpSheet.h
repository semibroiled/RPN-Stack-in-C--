#ifndef HELP_SHEET
#define HELP_SHEET

void helpSheet () {
    std::cout << "Some Instructions to help you along the tool"<<std::endl;

    std::cout << "Type in Mathematical Expressions using:";
    std::cout << std::endl;

    std::cout   << "-> '+' for Addition," << std::endl 
                << "-> '-' for Subtraction," << std::endl 
                <<  "-> '/' for Division," << std::endl 
                <<  "-> '*' for Multplication," << std::endl 
                << "-> '^' for Exponent";

    std::cout << std::endl;

    std::cout << "Expressions have to be in RPN or Postfix Notation;";
    std::cout << std::endl;

    std::cout << "You would write an inline expression 5+3 in RPN Notation as 5 3 +";
    std::cout << std::endl;

    std::cout << "Note that the expression tokens have to be separated by a space";
    std::cout << std::endl;
    std::cout << std::endl;
}



#endif

