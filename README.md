# advanced_cpp
This repository is designed and developed, to help the beginner to get a thourough understanding of the C++ programming language, and include the topics from Basic of C++ to the advanced/Modern C++ concepts.

# Content
## Basics of compilation
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
cmake .
step 2: to use the makefile to generate the executable runTests
make 
step 3: run the executable 
./runTests
6. version control tool: Git or GitLab
7. coverage analysis tool : gconv

