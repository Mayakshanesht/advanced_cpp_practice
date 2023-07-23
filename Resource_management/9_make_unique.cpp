#include <iostream>
#include <memory>
#include <string>

class Person {
public:
    Person(const std::string& name) : name_(name) {
        std::cout << "Constructor called. Created person: " << name_ << std::endl;
    }

    ~Person() {
        std::cout << "Destructor called. Deleted person: " << name_ << std::endl;
    }

    void introduce() {
        std::cout << "Hi, I am " << name_ << "." << std::endl;
    }

private:
    std::string name_;
};
/*int main() {
    std::unique_ptr<Person> ptr1(new Person("Alice"));
    std::unique_ptr<Person> ptr2(new Person("Bob"));

    // If an exception occurs before ptr2 is created, memory leak will happen
    // because ptr1 will not be automatically deleted.
    // ...
    
    return 0;
}
*/
int main() {
    auto ptr1 = std::make_unique<Person>("Alice");
    auto ptr2 = std::make_unique<Person>("Bob");

    // If an exception occurs before ptr2 is created, ptr1 will be automatically deleted.
    // ...

    return 0;
}
