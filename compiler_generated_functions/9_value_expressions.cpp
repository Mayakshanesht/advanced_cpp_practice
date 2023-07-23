#include <iostream>
#include <utility> // Required for std::move
using namespace std;

class Vector {
public:
    int* data;
    int size;

    Vector(int sz) : size(sz) {
        data = new int[size];
        cout << "Constructor called. Allocated " << size << " elements." << endl;
    }

    // Move Constructor using rvalue reference
    Vector(Vector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // Prevent other object from deallocating memory
        cout << "Move Constructor called." << endl;
    }

    ~Vector() {
        delete[] data;
        cout << "Destructor called. Deallocated memory." << endl;
    }
};

// Function to create a temporary Vector object with a large number of elements
Vector createVector(int size) {
    return Vector(size);
}

int main() {
    // Example 1: Without rvalue reference
    Vector obj1 = createVector(1000000);

    // Example 2: Using rvalue reference (move semantics)
    Vector obj2 = std::move(createVector(1000000));
    int a=10;
    int&& b=std::move(a);
    cout<<b<<endl;
  

    return 0;
}
