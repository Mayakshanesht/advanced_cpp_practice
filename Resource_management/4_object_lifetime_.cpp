#include <iostream>
#include <string>

class Person {
public:
    // Constructor
    Person(const std::string& name) : name_(name) {
        std::cout << name_ << " is born!" << std::endl;
    }

    // Destructor
    ~Person() {
        std::cout << name_ << " dies!" << std::endl;
    }

    // Member function
    void introduce() {
        std::cout << "Hi, I am " << name_ << "." << std::endl;
    }

private:
    std::string name_;
};

int main() {
    // Create a Person object with automatic storage duration (on the stack)
    Person alice("Alice");

    // Creating a Person object using dynamic memory allocation (on the heap)
    Person* bob = new Person("Bob");

    // Using the member function to introduce the objects
    alice.introduce();
    bob->introduce();

    // Explicitly deleting the dynamically allocated object to release memory
    delete bob;

    // Exiting the main function, which will destroy the automatic object "alice"
    return 0;
}
