#include<iostream>
#include<vector>
int main()
{
int c[]={1,2,3};
int d[5]={10,20,30,40,50};
int e[2][3]={6,5,4,3,2,1};
std::vector<int>::iterator i;
for(auto& i:d)
{
std::cout<<i<<std::endl;
}
return 0;
}
