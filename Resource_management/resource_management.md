# Resource Acquisition is Initialization
//chapter 3 Resource management
Resources
Types
Issues
solution
object
Object lifetime
RAII
Smart pointers- manage the dynamic memory and release the resource in the dynamic memory allocation
unique pointers - single pointers
shared pointers - poinetr shared between muitiple pointers
make_shared - single memory blcok for all the objects
make_unique- order of execution of the constructor and function call

## Resources

Resources must be acquired and released/disposed explicitly.
▶ Examples for resource types
Resource Acquisition Disposal
memory new delete
files fopen fclose
mutex lock unlock
thread create join
▶ common issues that might occur during resource management
▶ leak (losing the handle to a resource)
▶ double disposal
▶ usage after disposal

 leak
```bash
int main() {
int* x = new int{};
x = nullptr;
}
```
Yes, this code snippet has a memory leak. The variable x is assigned a pointer to a dynamically allocated integer using the new operator. However, before deleting the dynamically allocated memory, x is assigned a null pointer, which means the original memory location is lost and cannot be freed. Therefore, there is no way to free the memory that was allocated using new, causing a memory leak.

The following code leads to double disposal, which can cause undefined behavior:

arduino

int main() {
    int* x = new int{};
    delete x;
    delete x;
}

Double disposal:
Here, a dynamic integer object is allocated using new and the pointer to it is stored in x. Then, the object is properly deleted using delete x. However, the same pointer x is used to delete the object again, which causes undefined behavior.
```bash
int main() {
int* x = new int{};
delete x;
delete x;
}
```
In general, double disposal can cause memory corruption, heap corruption, and other serious problems. It is important to always ensure that each dynamic object is deleted exactly once using the delete operator.

Usage after disposal:
The third example in your previous question demonstrates the usage of an object after its disposal, which results in undefined behavior. Here's the corrected example:


```bash

int main() {
    int* x = new int{};
    delete x;
    int y = *x; // accessing a deleted object, undefined behavior
}

```
Accessing a deleted object can result in various problems, such as memory corruption or segmentation faults. It's important to avoid using objects after they've been deleted.

Solution to the memory leak:
we can avoid the memory leak using the delete function at the end of the code to delete the dynamically allocated memory.

## Object Lifetime
Object:
In C++, an "object type" refers to a type that can represent an object in memory. An object is a region of storage that can represent a value of a given type.

According to the C++ standard [basic.types], an object type is defined as any type that satisfies the following conditions:

    It is not a function type: a type that represents a function or a pointer to a function is not considered an object type.

    It is not a reference type: a type that represents a reference to an object is not considered an object type.

    It is not cv void: void is not considered an object type, as it cannot represent a value.

In other words, an object type is any type that can represent a value in memory, except for functions, references, and void. Examples of object types include fundamental types like int and double, user-defined types like classes and structures, and pointer types.

## Object Lifetime
n C++, the lifetime of an object refers to the period during which the object exists in memory and can be accessed by the program. The lifetime of an object is determined by its storage duration, which can be one of three types:

    Automatic storage duration: Objects with automatic storage duration are created when the program enters the block where they are defined, and are destroyed when the block is exited. For example, variables defined inside a function have automatic storage duration.

    Dynamic storage duration: Objects with dynamic storage duration are created using dynamic memory allocation functions such as new and malloc, and exist until they are explicitly deleted using the corresponding deallocation functions (delete and free).

    Static storage duration: Objects with static storage duration are created when the program starts and exist until the program ends. They are typically used for global variables and variables defined with the static keyword inside a function.

The lifetime of an object is important because accessing an object after its lifetime has ended leads to undefined behavior, which can cause crashes or other unexpected results in the program. It is the programmer's responsibility to ensure that objects are properly managed throughout their lifetime.

In C++, the construction and destruction order of objects  is defined as follows:

for the derived classes:
    Base classes are constructed before derived classes.
    Data members are constructed in the order in which they are declared in the class.
    The constructor body is executed after all base classes and data members have been constructed.
    The destruction order is the reverse of the construction order. Data members are destroyed in the reverse order of construction, followed by base classes.

for the objects:
It is important to note that if an object is created with automatic storage duration (i.e., not thread-local or static), its destructor will be invoked implicitly when the block in which the object is created exits. For objects with static storage duration, the destructor will be invoked when the program exits. For objects with thread-local storage duration, the destructor will be invoked when the thread exits.

Lifetime begin and end from C++ std [basic.life]
The lifetime of an object of type T begins when:
▶ storage with the proper alignment and size for type T is obtained, and
▶ its initialization (if any) is complete (including vacuous initialization), [...]
The lifetime of an object o of type T ends when:
▶ if T is a non-class type, the object is destroyed, or
▶ if T is a class type, the destructor call starts, or
▶ the storage which the object occupies is released, or is reused by an object that is not nested
within o.

```bash
Object lifetime – Awake?
# include <iostream>
struct A {
static int inst;
A(int i) { std::cout << " A()" << inst << "\n"; if(inst>=i) throw "error"; inst++; }
~A() { std::cout << "~A()" << --inst << "\n"; }
};
int A::inst=0;
struct X {
A *_a, *_b;
X(int i) : _a{new A{i}}, _b{new A{i}} { std::cout << " X()\n"; }
~X() { std::cout << "~X()\n"; delete _a; delete _b; }
};
int main(int argc, char* argv[]) {
int i=(argc>1?atoi(argv[1]):42);
try {
X x{i};
} catch (...) {}
}
```
In the previous example, if an exception is thrown during the construction of the X object, the A objects pointed to by _a and _b are not properly deallocated, leading to a memory leak.

When the exception is thrown, the constructor of X is not completed, and the delete statements in the X destructor are not executed, leaving the _a pointer without being deleted. This results in a memory leak since the memory allocated to _a is not returned to the operating system.

This problem occurs because the X class is responsible for managing the resources _a and _b. If X were only managing a single resource, then the problem would not occur. This is because the delete statement in the X destructor would be executed for the single resource, whether or not an exception was thrown during its construction.

This problem can be avoided by adhering to the Single Responsibility Principle (SRP), which states that a class should have only one reason to change. In this case, if the X class were responsible only for managing a single resource, then it would have only one responsibility, and the problem of the memory leak would be avoided.

RAII for dynamic memory
bool bad_code() {
int* i = new int{};
std::cin >> *i;
try {
do_something(i);
} catch (...) { std::cout << "exception\n"; delete i; throw; }
if (*i == 22) {
delete i;
return false;
}
std::cout << *i << std::endl;
delete i;
return true;
}

The given code uses dynamic memory allocation to create an int object pointed to by the i pointer. It then reads an integer value from the console and passes it to the do_something function. If an exception is thrown within the do_something function, the i pointer is deleted and the exception is re-thrown.

If the value of the int object pointed to by i is equal to 22, then the i pointer is deleted and the function returns false. Otherwise, the value of the int object is printed to the console, the i pointer is deleted, and the function returns true.

This code does not use RAII (Resource Acquisition Is Initialization) to manage the dynamically allocated memory. RAII is a technique in C++ where a resource, such as dynamic memory, is acquired during the construction of an object and released during the destruction of the object. This ensures that the resource is properly managed even in the presence of exceptions or early returns.

RAII is a fundamental technique in C++ for managing resources such as dynamic memory, file handles, and network sockets. It relies on the fact that objects in C++ are destroyed when they go out of scope or are explicitly deleted, which allows resources to be acquired during the construction of an object and released during the destruction of the object. By using RAII, we can ensure that resources are always properly managed, even in the presence of exceptions or early returns.

The basic idea behind RAII is to encapsulate the management of a resource in a C++ object, so that the object's constructor acquires the resource and the object's destructor releases the resource. This ensures that the resource is always released when the object goes out of scope or is explicitly deleted, regardless of how control flow exits the block in which the object is defined.

RAII can be implemented using various C++ features, including smart pointers, containers, and custom classes. Smart pointers such as std::unique_ptr, std::shared_ptr, and std::weak_ptr are particularly useful for managing dynamic memory, as they automatically delete the managed memory when the smart pointer goes out of scope or is reset. Containers such as std::vector and std::map also use RAII to manage their contents, and can be used to manage resources other than dynamic memory.

RAII is a powerful technique that can greatly simplify resource management in C++ code. By using RAII, we can avoid common programming errors such as memory leaks, double-deletes, and dangling pointers, and write code that is more robust, efficient, and maintainable.

To use RAII for dynamic memory in this code, we can replace the raw pointer i with a std::unique_ptr<int> object. std::unique_ptr is a smart pointer in C++ that uses RAII to manage dynamic memory. Here's how the code can be modified to use std::unique_ptr:

c

bool good_code() {
  std::unique_ptr<int> i{new int{}};
  std::cin >> *i;
  try {
    do_something(i.get());
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

In this modified code, the std::unique_ptr<int> object i is created using new int{}, which allocates dynamic memory for an int object and initializes it to zero. The std::unique_ptr object i automatically takes ownership of this memory and will automatically delete it when it goes out of scope or is reset.

The do_something function is called using the get method of the std::unique_ptr object, which returns a raw pointer to the managed object.

If an exception is thrown, the std::unique_ptr object i will automatically delete the managed memory when it goes out of scope due to the stack unwinding caused by the exception. This ensures that the dynamic memory is always properly managed, even in the presence of exceptions or early returns.
The shared ptr class template stores a pointer, usually obtained via new. shared ptr implements
semantics of shared ownership; the last remaining owner of the pointer is responsible for destroying
the object, or otherwise releasing the resources associated with the stored pointer. [...]
▶ shared ownership
▶ copyable and movable
▶ std::shared_ptr (defined in <memory>)
▶ be careful with shared pointers (memory leaks are still possible)
▶ shared pointer is twice the size of a raw pointer

Shared ownership: std::shared_ptr provides shared ownership semantics, which means that multiple std::shared_ptr objects can own the same resource (i.e., the same dynamically allocated object) at the same time. The last std::shared_ptr that goes out of scope or is reset is responsible for deleting the object.

    Copyable and movable: std::shared_ptr is both copyable and movable. When a std::shared_ptr is copied, the reference count is incremented, and when a std::shared_ptr is destroyed or reset, the reference count is decremented. When a std::shared_ptr is moved, the source std::shared_ptr relinquishes ownership of the resource, and the destination std::shared_ptr takes over ownership.

    Defined in <memory>: std::shared_ptr is a class template defined in the <memory> header in the C++ standard library.

    Be careful with shared pointers: Although std::shared_ptr provides shared ownership semantics and helps avoid memory leaks, it's still possible to create memory leaks if you're not careful. For example, if you create a cycle of std::shared_ptr objects that refer to each other, the reference count of each std::shared_ptr will never reach zero, and the objects will never be deleted.

    Shared pointer size: The size of a std::shared_ptr object is typically twice the size of a raw pointer. This is because in addition to storing the pointer to the resource, a std::shared_ptr also stores a pointer to a control block that contains the reference count and other information about the shared ownership of the resource.

std::make_shared<T> is more efficient than using std::shared_ptr<T>(new T(args...)) because it only allocates a single block of memory for both the object and the control block that manages the reference count. This can reduce the number of allocations and improve cache locality, which can lead to better performance and lower memory overhead.

Using std::make_shared<T> also avoids the problem of conflicting allocations in the constructor of the object, which can occur if the constructor of the object itself allocates memory. By using std::make_shared<T>, the memory for the object and the control block is allocated in a single block, so there is no possibility of conflicting allocations.

In addition, using std::make_shared<T> and std::make_unique<T> can avoid issues with the order of execution of constructor and function calls, which can occur when using std::shared_ptr<T>(new T(args...)) and std::unique_ptr<T>(new T(args...)). This is because the order of execution of function arguments is unspecified in C++, which means that the order in which the constructor and do_something(i) are executed is undefined. This can lead to memory leaks or other issues if the constructor throws an exception before the std::shared_ptr or std::unique_ptr is constructed.

By using std::make_shared<T> and std::make_unique<T>, we can ensure that the memory is allocated and managed correctly, regardless of the order of execution of the constructor and function calls.