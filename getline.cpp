#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    cout<<"enter the string"<<endl;
    string Mayur, Name;
    getline(cin,Mayur,' ');
    
    //stringstream(Mayur)>>Name;

    //to take the input  from the string
    //Mayur="Mayur Waghchoure";
    stringstream ss(Mayur);
    getline(ss,Name);
    
    cout<<Name<<endl;
    return 0;

}