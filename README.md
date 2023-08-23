# RPN-Stack-in-C++

## Introduction

RPN (Reverse Polish Notation) or Postfix Notation, is a form of notation
in which we write mathematical expressions beginning with the operands or numbers
of the expression, ending with their operators.

For example, we would write 2+2, which is in inline notation, as 2 2 +, in 
Postfix Notation.

For more complex expressions, we don't use parentheses to denote order of operations
as in with normal inline notation. To compute postfix expressions, we follow along
a specific algorithms using a stack.

## Computing RPN Expressions
### Stacks

A stack is a type of ordered collection, where values are put in a piling order,
ie, following FILO principle. Imagine a pile of books on a desk. The first book at the
bottom would be the last you would get to, going top down to inspect every book.

Stacks across programming languages have some common operatoins.

You can pop, ie remove, the top level of a stack. In some languages,
pop would also read out the value to you. In the context of C++, these are two
distinct operations.

You can push, ie insert values onto the top level succesively. 

In C++, you can call a stack Data Type from the Standard Library.

### RPN in Stack

Take the case of an RPN expressoin, 1 2 3 + -

To compute this expressions, you read from left to right.

Imagine you have an empty stack, where you can put in the values. Reading from 
left to write, if you see an integral or numerical value, you put the numbers in 
the stack. So, from the bottom up (remember, the values at the bottom level is
accessed last), you stack would read;
-top: 3
- 2
-bottom: 1

At which point, we come to the operators. When we come across the first operator,
which is the + sign, we expel the top two operands- the numbers to be operated on,
from the stack. So, we would take out first 3, then 2, subsequently performing the operatoin
3+2. The result is 5, and we put it back in the stack. We repeat this with the -
operator. We get the top two values in the stack, being 5 and 1 repectively.
1-5 computed is -4. This is our final result.

At the end of postfix notation, there are no more operators left, and we have
one value, the result, left on stack.

## Using the program

### Compiling and Running the Program

The code is separated into three files. The script running the calculator is in the main file.
With a C++ compiler, such as GCC or Clang, compile the individual files in the same path
in terminal.

Explained step by step,
1- Go to the path with the files in terminal
2- Compile files into object files
3- Run `g++ -c rpn_caculator.cpp`
4- Run `g++ -c main.cpp`

This generates a main.o and rpn_calculator.o file in your directory

6- Link the two files into an executable with `g++ -o calc main.o rpn_calculator.o`

This makes a binary executable calc in your path

7- Run the executable with `./calc` and follow through the instructions

At any time, type exit to quit the program from the terminal, help for
further instructions on how to operate the program. Here's an excerpt 
from the help files on running the program

Normally, I would have already compiled the calc binary exectuable. So, 
steps 1 through 6 are done for you. And you would only need to do the 7th step
to hop into the executable.

```

Enter a valid postfix expression. Type exit to to quit. Type help to get additonal instructions
>>help
Type in Mathematical Expressions with...
+ for Addition, - for Subtraction, / for Division, * for Multplication and ^ for Exponent
Expressions have to be in RPN or Postfix Notation, ie...
You would write an inline expression 5+3 in RPN Notation as 5 3 +
Note that the expression tokens have to be separated by a space

```

Acceptable responses are space separate and postfix. 

Examples are: 5 4 +, 5 9 1 + *, ...

### Design Decisions

The program is built with three files:

1) rpn_calculator.h
2) rpn_calculator.cpp
3) main.cpp

in 1 and 2, we add a RPNStackCalculator Class to take on the repetitive operations
into 3 method calls. A Stack Container is called in privately by the class whenever
we declare an instance.

in 3, we call a function externally to check whether something is an operator.

We parse our input string and call on the methods to run the Calculator.

Basic CLI Functionality is added in an infintie while loop with a bool switch.

The program is kept bare bones on purpose, as anything other than this would be 
needless overengineering. The task is simple to begin with. I've nevertheless packed
everything into its own unit files to allow, for example, future work on this to be 
easy and modular. As such, it can be expanded endlessly, for example, adding more 
methods in the rpn_calculator header and cpp file, or adding in more operations in the rpn_cal*.cpp
and main.cpp file, etc.

Optimally I would make this file with Cmake to allow for better distribution, which I will
still try to add in. As, one thing to note is, I've written the Readme in context
of a Mac Darwin Development Environment. As there are some glitched with lldb and GDB Debuggers,
I've instead opted out of it for the sake of simplicity.

I added in the Readme and variables in English, as that is the language of the internet far and wide.

It could also be prudent to add German Documentation for the steps shown here.







