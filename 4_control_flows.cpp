#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    // There are following data types inside the c++
    char a='M';
    string h="Mayur";
    bool b=0;
    // for the integers we have three choices based on the memory
    short c=0;
    int d=42798;
    long e=1234567891011;
    // float , decimal point type of the variables we have two choices
    float f=3.14;
    double g=3.141591254678;
    cout<<a<<"\n"<<h<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n"<<f<<"\n"<<g<<endl;
    
    // control flows - If else if else
    if (c<d)
    {
        cout<<e<<endl;
    }
    else if (c>d)
    {
        cout << a << endl;
    }
    else
    {
        cout << b << endl;
    }

    // switch case
    
    switch(3)
    {
        case 1:
        {
           cout <<"A"<< endl;
        }
        case 2:
        {
            cout << "B"<<endl;
        }
        default:
        {
            cout << "Z"<<endl;
        }
    }

    // for loop (initialization, condition, increment)
    int array[]={1,2,3,4,5};
    for (int i=0;i<=4;i++)
    {
        cout <<array[i]<<endl;
    }
    
    
    // vector and for loop
    vector<int> vector1={10,11,12,13,14};
    vector<int>::iterator it;
    for (auto it:vector1)
    {
        cout<<it<<endl;
    }

    // while loop
    int i=0;
    while(i<5)
    {
        cout <<"True"<<endl;
        i++;
    }

    // we could also use the do while loop to increment before checking the condition
    
    
   return 0;

}