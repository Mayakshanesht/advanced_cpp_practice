# advanced_cpp
This repository is designed and developed, to help the beginner to get a thourough understanding of the C++ programming language, and include the topics from Basic of C++ to the advanced/Modern C++ concepts.

# Content
## Basics of compilation
# Basics
There are two types of the programming languages, 
1. Interpreted languages (Python): Here, an Interpreter will interpret the source code and user inputs, that is, it would perform the compilation and running of the code at the same time, and gives the result.
Characteristics:
1. They are slow, dynamically typed means data types are need not to be defined, and easy for the rapid prototyping.

2. Compiled languages(C++, C): Here code has to be compiled first into the executable and then, it is run later on.
Compilation:
It consists of the four steps:
1. Preprocessing: In this step, the commented code will be removed. As well as, all the included library codes will be expanded, and added at the beginning of the program. 
2. Compiler: in the step, the source code will be converted into the assembly language mnemonics code by the compiler.
3. Assembler: In the step, Assembler will convert the assembly level code into the machine level code or the object code.
4. Linker: Since the object code from the different libraries have to be resolved into the final executable file, and that task will be done by the linker by connecting the object API and libraries to each other with the symbolic memory addresses.
Running:
5. Loader: In this step, executable with the symbolic memory addresses will be replaced by the actual memory addresses, and code will be executed.

Characteristics: It is a machine level and a hardware friendly fast programming language, is is a static typed means,the variable data types have to be defined at the compile time only, thus it is preferred for the safety critical applications.

# Code structure mainly consists of two parts,
1. pre-processor directive
2. main function

1. Preprocessor directive: This is , how c++ code begins. They are basically provided with the '#" sign followed by the keyword, and tell the compiler what all libraries to included,
1. It means the compiler should look for this library in the standard folder,

```bash
#include <iostream>
```


2. Including the file from the current directory,


```bash
#include "class.hpp"
```


3. We can also define the constants, inclusion guards with the help of macros,
```bash
#define G 9.81
#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
```
it should end with the help of at the end of the header file,

```bash
#endif /*CLASS_H_INCLUDED*/
```


4.Namespace: This allows us to avoid using the same code again and again, and we can replace the with a keyword,
```bash
using namespace std;
```


2. Main Function: It is the function where the main code will be run, and it will return always the integer output to be 0.
```bash
int main()
{
    int a,b;
    std::cout << "enter value of a" << std::endl;
    std::cin >> a;
    std::cout << "enter value of b" << std::endl;
    std::cin>> b;
    int c=a+b;
    std::cout<<c<<std::endl;
    return 0;

}
```

Inside the main function, we are supposed to define all the variables and perform the operations to produce the output.

To compile this code, we need to save this as class.cpp file and then run the following command in the terminal,
```bash
g++ -std=c++11 <main file name> <class file name> -o <output name>
```

```bash
g++ -std=c++11 basic.cpp -o basic
```

to run it,
```bash
./basic
```
## Cin, Cout, getline, stringstream, namespace, macros, inclusion brackets
## Arithmetic, assignment, relational, logical operators
## control loops
## Pointers
## Functions
## this pointer
## Arrays
## Classes
## Overloading
## templates- generic programming
## Inheritance and Multiple inheritances, access modofiers
## Polymorphism
## Pointers to the class and statically bound classes
## Virtual functions: Make them bound dynamically during the execution
## Vectors- assign, push_back, insert, emplace, clear, erase, pop_back
## iterators - to move through the vectors, start with the begin and end with the end, and can access vector elements using the dereferncing
## Static variables: shared variable between the multiple instances of the same class, use the keyword static, saves the space but slow execution
## friend methods: which can have access to the private and protected members of the base class
## global variables
## testing the code with the help of gtest
## strings-input and output
## optimization: use the execution command  g++ std=c++11 -03 main.cpp to speed up the execution
## Design>>implement>>test>>optimize
## optimize:
c++ code
algorithms
compiler- -03 flag
hardware> small angle approximations
chapter 1:
1. code editor and debugger: VS code
2. compiler: g++
3. build tool: make, which would need the Makefile, to get this we would need the cmake as a configuration tool
4. configuration tool: cmake, write CMakeLists.txt file
5. gtest: 
here we have used gtest to perform the testing, to run it we need to write the cmake file,
steps to run the tests,
step 1: to build the CMakeLists.txt file and get the MakeFile
```bash
cmake .
```

step 2: to use the makefile to generate the executable runTests
```bash
make
```
step 3: run the executable 
```bash
./runTests
```

6. version control tool: Git or GitLab
7. coverage analysis tool : gconv

