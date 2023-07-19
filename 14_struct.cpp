#include <iostream>

enum Color {
  RED,
  GREEN,
  BLUE
};
struct data{
  int a=10;
  float b=20;
};

int main() {
  std::cout << "The value of RED is: " << RED << std::endl;
  std::cout << "The value of GREEN is: " << GREEN << std::endl;
  std::cout << "The value of BLUE is: " << BLUE << std::endl;
  data data1;
  std::cout<<data1.a<<std::endl;
  return 0;
}