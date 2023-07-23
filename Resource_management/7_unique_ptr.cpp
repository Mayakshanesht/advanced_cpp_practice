# include <iostream>
# include <memory>
struct X {
X() { std::cout << "X\n"; }
~X() { std::cout << "~X\n"; }
};
void f(std::unique_ptr<X> const& x) { std::cout << "f\n"; }
void g(std::unique_ptr<X> x) { std::cout << "g\n"; }
int main() {
std::unique_ptr<X> x(new X{});
f(x);
g(std::move(x));
std::cout << "end of main\n";
}