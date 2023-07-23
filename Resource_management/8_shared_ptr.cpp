# include <iostream>
# include <memory>
struct X {
X() { std::cout << "X\n"; }
~X() { std::cout << "~X\n"; }
};
void f(std::shared_ptr<X> x) { std::cout << "f\n"; }
int main() {
std::shared_ptr<X> x1(new X{}), x2{x1};
std::cout << "use_cnt: " << x1.use_count() << std::endl;
f(std::move(x1));
std::cout << "use_cnt: " << x1.use_count() << std::endl;
std::cout << "use_cnt: " << x2.use_count() << std::endl;
std::cout << "end of main\n";
}
