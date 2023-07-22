#include <iostream>
using namespace std;

class MyClass {
public:
    // Compiler-generated default constructor
    MyClass() {
        cout << "Default Constructor called!" << endl;
    }
};

int main() {
    MyClass obj; // Creating an object, default constructor is called
    return 0;
}
