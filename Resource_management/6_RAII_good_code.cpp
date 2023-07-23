#include <iostream>
#include <memory>
void doSomething() {
        std::cout << "Resource is being used for some operation." << std::endl;
    }
bool good_code() {
  std::unique_ptr<int> i{new int{}};
  std::cin >> *i;
  try {
    doSomething();
  } catch (...) {
    std::cout << "exception\n";
    throw;
  }
  if (*i == 22) {
    return false;
  }
  std::cout << *i << std::endl;
  return true;
}
int main()
{
    good_code();
    return 0;
}