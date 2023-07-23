#include <iostream>
void doSomething() {
        std::cout << "Resource is being used for some operation." << std::endl;
    }
bool bad_code() {
int* i = new int{};
std::cin >> *i;
try {
  doSomething();
} catch (...) { std::cout << "exception\n"; delete i; throw; }
if (*i == 22) {
delete i;
return false;
}
std::cout << *i << std::endl;
delete i;
return true;
}
int main()
{
    bad_code();
    return 0;
}
