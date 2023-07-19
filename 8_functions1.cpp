#include <iostream>
using namespace std;
int increment(int a);
int increment1(int &a);
//void increment2(int *array);
//void increment2(int array[]);
void increment2(int array[5]);
int main()
{
    int b[]={1,2,3,4,5};
    int c=4;
    int d=increment(c);
    int e=increment1(c);
    increment2(b);
    cout <<d<<endl;
    cout <<e<<endl;
    return 0;
}
int increment(int a)
{
    return ++a;
}
int increment1(int &a)
{
    return ++a+1;
}
void increment2(int array[5])
{
    for (int i=0;i<5;++i)
    {
    array[i]=array[i]+1;
    cout<<array[i]<<endl;
    }
}