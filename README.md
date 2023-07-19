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
1. constants using macros: can be added to the pre-processor directives
```bash
#define G 9.81
```
2. single constants: its value will not change during the execution of the program, and can be added to the main function
const int a=4;

3. We could create the new variable type either using the keyword,
3.1 using
using c=char;
using word=std::string;

3.2 enum keyword
In C++, an enumerated type (or enum) is a user-defined data type that consists of a set of named constants. Each of these named constants is assigned an integer value by the compiler, starting with 0 and incrementing by 1 for each subsequent constant.

Here's an example of how to define an enum in C++:
```bash
enum Color {
  RED,
  GREEN,
  BLUE
};
```


In this example, we define an enum called Color with three named constants: RED, GREEN, and BLUE. The compiler will automatically assign integer values to these constants, starting with 0 for RED, 1 for GREEN, and 2 for BLUE.

3.3 typedef
typedef char c;
typedef std::string word;



4. Formating the output using the escape sequences:
 Once it is included, you can format output using the iomanip library. For example, we can set the width of an output using the setw command.

In C++, a stringstream is a stream class that allows you to operate on strings as if they were input/output streams. This means that you can use the same operators (<< and >>) that you use with cin and cout to read from and write to strings.

In the Stringstream Programming Quiz, you will see how to use stringstream with getline. getline is a function that reads a line from an input stream and stores it in a string. It takes two parameters: the input stream and the string to store the line in.

Here's an example of how to use stringstream with getline:
```bash
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string input = "Hello World";
  std::stringstream ss(input);
  std::string output;
  getline(ss, output, ' ');
  std::cout << output << std::endl;
  return 0;
}
```


In this example, we create a string called input and initialize it with the value "Hello World". We then create a stringstream called ss and initialize it with the value of input. We create a string called output to store the output of getline. We then call getline with ss as the input stream, output as the string to store the line in, and ' ' as the delimiter. This will read the first word from input and store it in output. We then print output to the console.

## Arithmetic, assignment, relational, logical operators
## Arithmetic operations in C++ are similar to other languages. 
+ Addition
- Subtraction
* Multiplication
/ Division
% modulo - remiander

When doing math operations you may need to include the cmath library, it contains a number of useful functions.

One that you may find useful is: std::pow(base, exponent).
```bash
#include<cmath>

//std::pow(base, exponent)

//3^5 is equal to std::pow(3, 5)
int main()
{
 std::pow(3, 5);

 //pi is equal to M_PI
M_PI = 3.14159265358979323846;
```
## Variable assignment:
C++ is a language that requires variable types to be known at compile time.

But, C++ does allow some implicit conversions, for example an integer can be assigned to a float or an integer can be treated as a char. 


char
bool
int (short,int, long)
float (float,double)
void
```bash
```bash
     #include <iostream>

     int main()
     {
          float width = 4.5;
          float height = 5.5;

          int area = width * height;
          std::cout << "area = " << area;
          return 0;
     }
```
## Assignment operators
+=,-=,*=,/=,%=

## Relational operator
```bash
#include<iostream>
#include<string>

int main()
{
    //instead of printing 0 and 1, create an array where 
    //0 = False, 1 = True
    std::string TorF[] = {"False", "True"};
    
    int a = 100;
    int b = 33;
    int c = 33;
    
    //Print out the string values of each relational operation
    std::cout<<"a < b is "<<TorF[a<b];
    std::cout<<"\na > b is "<<TorF[a>b];
    std::cout<<"\na != b is "<<TorF[a!=b];
    std::cout<<"\nc >= b is "<<TorF[c>=b];
    std::cout<<"\nc <= b is "<<TorF[c<=b];    
    return 0;
}
```

## Logical operator
```bash
/*Goal: understand the logical operators supported by C++
*/

#include<iostream>
#include<string>

int main()
{
    int A = 5;
    int B = 4;
    int C = 5;
    int D = 0;
    
    std::string TorF[] = {"False", "True"};
    
    //The && operator
    std::cout<<"A == C is "<<TorF[A==C];
    std::cout<<"\n(B == D) is "<<TorF[B==D]; 
    std::cout<<"\n(B > D) is "<<TorF[B>D]; 
    //A true && false = false
    std::cout<<"\n\n(A ==C) && (B == D) is "<<TorF[(A ==C) && (B == D)];  
    //A true and true = true
    std::cout<<"\n(A ==C) && (B > D) is "<<TorF[(A ==C) && (B > D)];     

    //The || operator
    //A true || false = true
    std::cout<<"\n\n(A ==C) || (B == D) is "<<TorF[(A ==C) || (B == D)];  
    //A true || true = true
    std::cout<<"\n(A ==C) || (B > D) is "<<TorF[(A ==C) || (B > D)];  
    
    //The 'Not' operator
    std::cout<<"\n\nA < B is "<<TorF[A<B];
    std::cout<<"\n!(A < B) is "<<TorF[!(A<B)];
    
    std::cout<<"\n\nA == C is "<<TorF[A==C];
    std::cout<<"\n!(A == C) is "<<TorF[!(A==C)];    
    
    return 0;
}
```
In C++, as in many languages, there are postfix and prefix operators.
The form for each is:

Incrementing

    prefix: ++a

    postfix: a++ 

Decrementing

    prefix: --a
    postfix: a-- 

The difference between prefix and postfix is subtle, but crucial.

Prefix operators increment the value of the variable, then return the reference to the variable.

Postfix operators create a copy of the variable and increments the value of the variable. Then it returns a copy from BEFORE the increment.
## control loops
1. if(condition), else if (condition), else
2. switch (condition) case ():.....; default:
3. for (int i=0;i<=10;i++) or for(auto iterator:range)
4. initialization; while(condition){increment}
5. initialization; do {increment}while(condition);

## Pointers
# Pointer
 Pointer is the variable, which stores the address of another variable, and it is defined with (*)asterisk sign
```bash
{
int b=0;
int *a=&b;
cout<<a<<endl;
cout<<*a<<endl;
return 0;
}
```
Arrays: It would allow the storage of data elements of the same type in one container and they are defined as,
C++ arrays can be declared as:
``` variableType arrayName [ ] = {variables to be stored in the array}; ``` or as: ``` variableType arrayName[array size] ```

Information about arrays can be found at:
[C++ Arrays](https://www.tutorialspoint.com/cplusplus/cpp_arrays.htm)
We can access the values in an array by identifying the specific index.
``` variableType arrayName[ index number ] ```
```bash
{
int c[]={1,2,3};
int d[5]={10,20,30,40,50};
int e[2][3]={6,5,4,3,2,1};
for(int i=c)
{
cout<<i<<endl;
}
return 0;
}


}
```
# Functions
call by value
call by reference : to return the variable out of the scope of function
call by reference for the array: three formats

C++ has a pointer called 'this'.

'this' returns its own address.

There are a few cases where 'this' might be necessary, but often using it is considered a stylistic preference.

Note in the program below, to compare the Area of the Shape's own area with the area of the shape

  //Use 'this' to compare areas
 //The class functions
      int compareWithThis(Shape shape) 
      {
         //return the area of the calling shape
         return this->Area() > shape.Area(); 
      }
## Classes : header file- method declaration, class file- method definitions
## Overloading, function overloading, and operator overloading
## templates- generic programming:for the functions, template<typename T, typename U> or for the class , template<class T>, while calling the class classname<datatype> objectname
## Inheritance and Multiple inheritances, access modofiers: child class
## Polymorphism
## Pointers to the class and statically bound classes: allocating the memory to the pointer using the new keyword and deleting it with the delete keyword.
## Virtual functions: Make them bound dynamically during the execution
## Vectors- assign, push_back, insert, emplace, clear, erase, pop_back
## iterators - to move through the vectors, start with the begin and end with the end, and can access vector elements using the dereferncing
## Static variables: shared variable between the multiple instances of the same class, use the keyword static, saves the space but slow execution
## friend methods: which can have access to the private and protected members of the base class
In C++, a "friend" method is a function or a class that is granted access to the private and protected members of another class. This allows the friend function or class to manipulate the private and protected members of the other class, even though they are not members of that class.

To declare a function or class as a friend of another class, the friend keyword is used in the class definition. Here is an example:

arduino

class MyClass {
private:
  int x;
  void privateMethod();
public:
  friend void friendFunction(MyClass& obj);  // friend function declaration
  friend class FriendClass;                  // friend class declaration
};

In this example, the friendFunction() and FriendClass are declared as friend entities of MyClass. They can access the private and protected members of MyClass.

Here's an example of a friend function that accesses the private member of MyClass:

vbnet

void friendFunction(MyClass& obj) {
    obj.x = 10;     // friend function can access private member of MyClass
    obj.privateMethod(); // friend function can access private method of MyClass
}

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
# How to run the tests using the CMakeLists.txt file
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

