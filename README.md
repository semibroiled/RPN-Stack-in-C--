# RPN-Stack-in-C++

## Index

## Documentatoin in English
## Introduction

RPN (Reverse Polish Notation) or Postfix Notation, is a form of notation
in which we write mathematical expressions beginning with the operands or numbers
of the expression, ending with their operators.

For example, we would write `2+2`, which is in inline notation, as `2 2 +`, in 
Postfix Notation.

For more complex expressions, we don't use parentheses to denote order of operations
as in with normal inline notation. To compute postfix expressions, we follow along
a specific algorithms using a stack.

Inline Expressions are converted into RPN using the Stunting Yard Algorithm.

## 1. Computing RPN Expressions
### 1.1. Stacks

A stack is a type of ordered collection, where values are put in a piling order,
ie, following FILO principle. Imagine a pile of books on a desk. The first book at the
bottom would be the last you would get to, going top down to inspect every book.

Stacks across programming languages have some common operatoins.

You can pop, ie remove, the top level of a stack. In some languages,
pop would also read out the value to you. In the context of C++, these are two
distinct operations.

You can push, ie insert values onto the top level succesively. 

In C++, you can call a stack Data Type from the Standard Library.

### 1.2. RPN in Stack

Take the case of an RPN expressoin, 1 2 3 + -

To compute this expressions, you read from left to right.

Imagine you have an empty stack, where you can put in the values. Reading from 
left to write, if you see an integral or numerical value, you put the numbers in 
the stack. So, from the bottom up (remember, the values at the bottom level is
accessed last), you stack would read;

```
|------|---|
|top   | 3 |   
|......| 2 |  
|bottom| 1 | 
------------
```


At which point, we come to the operators. When we come across the first operator,
which is the + sign, we expel the top two operands- the numbers to be operated on,
from the stack. So, we would take out first 3, then 2, subsequently performing the operatoin
3+2. The result is 5, and we put it back in the stack. We repeat this with the -
operator. We get the top two values in the stack, being 5 and 1 repectively.
1-5 computed is -4. This is our final result.

At the end of postfix notation, there are no more operators left, and we have
one value, the result, left on stack.

## 2. Using the program

### 2.1. Compiling and Running the Program in Terminal with GCC

#### 2.1.1. Compiling RPN Calculator in Command Line to build/bin/

The code is separated into 5 files. The script running the calculator is in the main.cpp file.
With a C++ compiler, such as GCC or Clang, compile the individual files *.cpp in the path `./src/`
in terminal. For this, I assume to be using a GCC compiler already in PATH on a Mac Computer.

Explained step by step,
1) Go to the path with the files in terminal in root directory `RPN Stack in C++`
2) Compile files into object files
2a)) Run `g++ -c src/rpn_caculator.cpp`, assuming you're in the root `.` directory
2b)) Run `g++ --std=c++17 c src/main.cpp`

Note: In general, best use -std=c++17 if any versioning errors pop up in build

This generates a `main.o` and `rpn_calculator.o` file in your root directory

3) Link the two files into an executable in the build/bin/ directory; `g++ -o build/bin/calc main.o rpn_calculator.o`

This makes a binary executable named calc in the specified path. This name can be anything.

4) Run the executable with `build/bin/calc` and follow through the instructions in program

At any time, 
- type in `exit` to quit the program from the terminal, 
- type in `help` for further instructions on how to operate the program. 
- type in `in` to change mode to Inline Expression Mode
- type in `post` or `rpn` to change mode to RPN Expression Mode

Here's an excerpt from the help files on running the program.

```

```

Acceptable responses are space separated in postfix notation. 

_Examples are:_ 
- 5 4 +, 
- 5 9 1 + *,
- ...

Inline notation allows space separated entries with usage of only '(' adn ')'
as brackets. 

Normally, I would have already compiled the calc binary exectuable. So, 
steps 1 through 4 are done for you. And you would only need to do the 4th step
to hop into the executable.

#### 2.1.2. Compiling and Running Tests

The `src` directory also has a test file with which we can validate the efficacy of the program in the `RPNStackCalculator` Class. Here's how you can compile and run it yourself to test it.

In the `src/test_rpn_calculatpr.cpp` file, insert in your own expressions and values to test in `expressions` and `expectResults` array, defined in Line 9 and 19 respectively. By default, you can also work with the values there.

The steps are similar to compiling and linking the `main.cpp` file. 

Explained step by step,
1) Go to the path with the files in terminal in root directory `RPN Stack in C++`
2) Compile files into object files
2a)) Run `g++ -c src/rpn_caculator.cpp`, assuming you're in the root `.` directory.
This may already be done from 2.1.1.
2b)) Run `g++ -std=c++17 -c src/test_rpn_calculator.cpp`. This change with the `-std` is important, because at least in my computer, the `std::size` in Line 21 wouldn't compile otherwise.

This generates a `test_rpn_calculator.o` and `rpn_calculator.o` file in your root directory

3) Link the two files into an executable in the build/bin/ directory; `g++ -o build/bin/test_calc test_rpn_calculator.o rpn_calculator.o`

This makes a binary executable named test_calc in the specified path. This name can be anything of your choice.

4) Run the executable with `build/bin/test_calc` and the assertion results print to terminal. In case of errors, you would see something going wrong. 

Normally, I would have already compiled the test_calc binary exectuable. So, 
steps 1 through 4 are done for you. And you would only need to do the 4th step
to hop into the executable.

As of implementing the Inline Functionality in current branch, the test cases 
are yet to be updated different format to test for edge cases. Most tests 
were done off repo in a prototyping file.

### 2.2. Compiling the program with Cmake and Make

Again, I am assuming this to be done on a Darwin Mac Computer. I expect it to be slightly modified on a Windows computer. Linux/Ubuntu should be the same.

1) Go to an appropriate directory in build. I usually build in `build/Debug`. If the directory isn't there, you can make a new named folder. 
2) If there are already CMake files in there, delete the cache to make a new one if that is necessary, or jump to step X.
3) From your path, `build/Debug`, `build/Release` or `build/Test`; run `cmake ../..`
- Basically, we're calling to the `CMakeLists.txt` file in the root directory, which contains build instructions. 
4) Once the build is done, and there are CMake files in your current directory, there would also be a `Makefile` file created.
5) Run `make` from that path, and the executables `rpn_calculator` and `test_calculator` will be created in the same directory
6) Run `./rpn_calculator` or `./test_calculator` to run the executables

I should have already built them on push to the repositary (under `build/Release` in circumstances).
Either run the Commands from Step 6 there, or run `build/Release/rpn_calculator` or test with `build/Release/test_calculator`.
### 2.3. Design Decisions

The program is built with five files in src:

1) main.cpp
2) rpn_calculator.cpp
3) rpn_calculator.h
4) func_operator.h
5) helpSheet.h
6) infixToPostfix.h
7) validateInput.h
8) test_rpn_calculator.cpp

- in 2 and 3, we add a RPNStackCalculator Class to take on the repetitive operations into three method calls.A Stack Container is called in privately by the class whenever we declare an instance.

- in 4, we define an array of functions externally to check whether something is an operator, paranthesis, and also assign operator importance.

- in 5, we add in terminal output to help users in the terminal upon usage

- in 6, we add in the functionality of changing notations from infix

- in 7, we define a function that checks for illegal characters in the expression with a high degree of modularity

- in 1, the whole porgram is expose as an endpoint CLI 

- in 8, we define some simple assertions tests to inspect edge cases and bugs

##### Some Closing Remarks

We parse our input string and call on the methods to run the Calculator.

Basic CLI Functionality is added in an infintie while loop with a bool switch.

The program is kept bare bones on purpose, as anything other than this would be 
needless overengineering. This has become quite the extensive and large build as is. 

The task is simple to begin with. I've nevertheless packed
everything into its own modular files to allow future work on this to be 
easy and error averse. As such, it can be expanded endlessly by, for example, adding more 
methods in the rpn_calculator header and .cpp file, or adding in more operations in the rpn_calculator.cpp
and func_operator.h file, etc.

Optimally I would make this file with Cmake to allow for better distribution, which I will
still try to add in. I opted to do this manually, which is possible but difficult, as VSCode isn't being cooperative(There are some glitched with lldb and GDB Debuggers and config files).

I've written the Readme in context of a Mac Darwin Development Environment.

Add any point, the commands help, quit helps the user get more bang for the buck out of this program.

Users can also change between Inline and RPN Notation. The expressions is evaluated in Postfix. Any Infix is converted to Postfix, when run on Inline mode. 

There is an extensive use of guard clauses to rule out edge cases and validate inputs, for example.

All in all, I think this project demonstrated good practice in code writing, linting, formatting, project management, unit testing, modular expansion, proper use of functional and OOP approaches. I consider this a success. 

## Dokumentaion auf Deutsch 







