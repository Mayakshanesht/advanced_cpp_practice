#include <iostream>
#include <iomanip>
#include <string>
// define the constant using the macro
#define DOB 19950507
#define Name "Mayur"
using namespace std;
// define the variable using the typedef
typedef float c;
// define the variables using the using
using D=int;

int main()
{
    int a = DOB;
    string myName=Name;
    const int b=2;
    D d=20.5;
    c e=3;
    
    if(b==2)
    {
    std::cout<< d <<"\n";
    std::cout<< e <<"\n";
    }
    return 0;
}
