# include <iostream>
using std::cout;
class X {
public:
X() { cout << "X() -> "; }
X(X const&) { cout << "X(X const&) -> ";}
X& operator=(X const&) { cout << "operator=(X const&) -> "; return *this; }
~X() { cout << "~X()\n"; }
};
X make_X() { return X{}; }
int main () {
X x{};
x = make_X();
return 0;
}