# Polymorphism in C++: A Comprehensive Guide

## Table of Contents
1. [What is Polymorphism?](#1-what-is-polymorphism)
2. [Types of Polymorphism](#2-types-of-polymorphism)
   - [Static Polymorphism (Early Binding)](#a-static-polymorphism-early-binding)
     - [Function Overloading](#function-overloading)
     - [Operator Overloading](#operator-overloading)
   - [Dynamic Polymorphism (Late Binding)](#b-dynamic-polymorphism-late-binding)
     - [Virtual Functions and Inheritance](#virtual-functions-and-inheritance)
     - [Abstract Classes and Pure Virtual Functions](#abstract-classes-and-pure-virtual-functions)
3. [Mechanism: Virtual Table (vtable)](#3-mechanism-virtual-table-vtable)
4. [Key Differences: Overloading vs. Overriding](#4-key-differences-overloading-vs-overriding)
5. [Pitfalls and Best Practices](#5-pitfalls-and-best-practices)
6. [Summary](#6-summary)

---

## 1. What is Polymorphism?
Polymorphism allows objects of different classes to be treated as objects of a common superclass. It enables **flexibility** and **dynamic behavior** in object-oriented programming (OOP). In C++, polymorphism is achieved through:
- **Compile-time (static) polymorphism**: Resolved during compilation (e.g., function/operator overloading).
- **Runtime (dynamic) polymorphism**: Resolved during runtime (e.g., `virtual` functions).

---

## 2. Types of Polymorphism

### A. Static Polymorphism (Early Binding)
#### Function Overloading
```cpp
#include <iostream>
using namespace std;

void print(int i) {
    cout << "Integer: " << i << endl;
}

void print(double d) {
    cout << "Double: " << d << endl;
}

void print(const string& s) {
    cout << "String: " << s << endl;
}

int main() {
    print(10);       // Calls print(int)
    print(3.14);     // Calls print(double)
    print("Hello");  // Calls print(const string&)
    return 0;
}
```

#### Operator Overloading
```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload '+' operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    friend ostream& operator<<(ostream& os, const Complex& c);
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex a(1, 2), b(3, 4);
    Complex c = a + b;
    cout << c; // Output: 4 + 6i
    return 0;
}
```

### B. Dynamic Polymorphism (Late Binding)
#### Virtual Functions and Inheritance
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const { // Base class virtual function
        cout << "Drawing a generic shape." << endl;
    }
    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape {
public:
    void draw() const override { // Override for Circle
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override { // Override for Rectangle
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Shape* shapes[] = {new Circle(), new Rectangle(), new Shape()};

    for (Shape* shape : shapes) {
        shape->draw(); // Calls appropriate draw() based on object type
        delete shape;
    }

    return 0;
}
```

---

## 3. Mechanism: Virtual Table (vtable)

### 1. What is a Virtual Table?
Definition: A vtable is a hidden, compiler-generated lookup table of function pointers. Each class with virtual functions (or derived from such a class) has its own vtable.

Purpose: It allows the program to determine which function to call at runtime based on the actual type of the object, rather than its declared type.

**Key Components:**
- **Virtual Table (vtable):** Stores addresses of virtual functions for the class.
- **Virtual Pointer (vptr):** A hidden pointer inside every object, pointing to its class’s vtable.

### 2. How the Vtable and Vptr Work
- **Step 1: Compiler-Generated Vtables**
- **Step 2: Inheritance and Vtable Construction**
- **Step 3: Runtime Dispatch**
- **Step 4: Multiple Inheritance Handling**

### 3. Memory Layout Example
Illustrating how objects store vptr along with their data members.

### 4. Pure Virtual Functions and Abstract Classes
- Abstract classes enforce interfaces in C++.

### 5. Vtables and Destructors
- Virtual destructors ensure proper cleanup when deleting derived objects via base class pointers.

### 6. Overhead and Performance
- Memory overhead due to vptr.
- Minor runtime overhead from dynamic dispatch.

### 7. Example: Vtables in Action
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal sound\n"; }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "Meow!\n"; }
};

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();

    a->speak(); // Output: Woof!
    b->speak(); // Output: Meow!

    delete a;
    delete b;
    return 0;
}
```

---

## 4. Key Differences: Overloading vs. Overriding
| Overloading | Overriding |
|-------------|-----------|
| Same function name, different parameters | Same function signature in derived class |
| Resolved at compile time | Resolved at runtime using virtual |
| Within the same scope | Across base and derived classes |

## 5. Pitfalls and Best Practices
- Virtual destructors
- Avoid slicing
- Understand runtime costs

## 6. Summary
- Polymorphism enables flexibility in object-oriented design.
- Vtables power dynamic polymorphism in C++.
- Understanding vtables helps optimize performance and debug code efficiently.

