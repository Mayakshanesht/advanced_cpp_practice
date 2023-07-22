# include <vector>
#include <iostream>
using namespace std;
// member intilizer list
class X {
public:
    int i;
    std::vector<double> v;
    double* p;
    X() :
    i{5},
    p{nullptr}
    { }
};
int main() {
X x{};
cout<<x.i<<'\n'<<x.p<<endl;
}