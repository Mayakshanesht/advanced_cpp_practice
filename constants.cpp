#include <iostream>
#include <iomanip>
#include <string>
// define the constant using the macro
#define DOB 19950507
#define Name "Mayur"
using namespace std;
typedef float c;
using D=int;

int main()
{
    int a = DOB;
    string myName=Name;
    const int b=2;
    D d=20;
    c e=3.14;
    
    if(b==2)
    {
    std::cout<< a <<"\n";
    std::cout<< myName <<"\n";
    }
    return 0;
}
