#include <iostream>
# include <utility>
using namespace std;
class X {
public:
int i{22};
double* p{nullptr};
X() = default;
X(X const & other)=default;
X& operator=(X const & other)=default;
X(X && other) : i{std::move(other.i)}, p{std::move(other.p)} { other.p = nullptr; }
X& operator=(X && other) {
if (this == &other) return *this;
i=std::move(other.i);
p=std::move(other.p); other.p = nullptr;
return *this;
}
};
int main() {
X x1{};
cout<<&(x1.i)<<'\n'<<&(x1.p)<<endl;
X x2 = std::move(x1);
cout<<&(x2.i)<<'\n'<<&(x2.p)<<endl;
x1 = std::move(x2);
cout<<&(x1.i)<<'\n'<<&(x1.p)<<endl;

return 0;
}