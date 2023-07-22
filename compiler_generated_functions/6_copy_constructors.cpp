# include <vector>
#include <iostream>
using namespace std;
class X {
public:
int i{22};
double* p{nullptr};
X() = default;
X(X const& other) : i{other.i}, p{other.p} { }
X& operator=(X const& other) {
if (this == &other) return *this;
i=other.i;
p=other.p;
return *this;
}
};
int main() {
X x1{};
cout<<x1.i<<'\n'<<x1.p<<endl;

X x2 = x1;
cout<<x2.i<<'\n'<<x2.p<<endl;
x2.i=5;
x2.p=nullptr;
x1 = x2;
cout<<x1.i<<'\n'<<x1.p<<endl;
return 0;
}