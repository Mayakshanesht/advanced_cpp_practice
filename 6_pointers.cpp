#include <iostream>
#include <vector>
using namespace std;
int main()
{
int b=0;
int *a=&b;
cout<<a<<endl;
cout<<*a<<endl;

// about the arrays
int c[]={1,2,3};
int d[5]={10,20,30,40,50};
int e[2][3]={6,5,4,3,2,1};
for(auto i:c)
{
cout<<i<<endl;
}
for (auto j:d)
{
cout <<j<<endl;
}

return 0;
}