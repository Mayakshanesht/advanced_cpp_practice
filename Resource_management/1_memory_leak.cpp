#include <iostream>
#include <memory>
using namespace std;
int main() {
int* x = new int{};
*x=10;
cout<<*x<<endl;
x = nullptr;
cout<<*x<<endl;
return 0;
}