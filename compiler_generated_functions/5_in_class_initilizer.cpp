# include <vector>
#include <iostream>
using namespace std;
// in class intilizer
class X {
public:
int i{5};
std::vector<double> v;
double* p{nullptr};

X() = default;
};
int main() {
X x{};
cout<<x.i<<'\n'<<x.p<<endl;
}