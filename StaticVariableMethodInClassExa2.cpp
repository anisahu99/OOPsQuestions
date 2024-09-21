#include<bits/stdc++.h>
using namespace std;

class Example {
private:
    int id;                          // Non-static member (unique to each object)
    static int objectCount;           // Static member (shared across all objects)
    // Global to Class

public:
    // Constructor to initialize 'id' and increment the object count
    Example(int i) : id(i) {
        objectCount++;
    }

    // Static function to get the current object count
    // Static Method cannot use Non-static member of a class
    static int getObjectCount() {
        return objectCount;
    }

    // Non-static function to get the object's id
    void display() const {
        cout << "ID: " << id << endl;
    }
};

// Initialize static member variable (needs to be defined outside the class)
int Example::objectCount = 0;

int main() {
    Example obj1(101);    // Create object 1
    Example obj2(102);    // Create object 2

    // Display IDs of individual objects
    obj1.display();       // Output: ID: 101
    obj2.display();       // Output: ID: 102

    // Access static member via the class (no need for an object)
    cout << "Total objects created: " << Example::getObjectCount() << endl; // Output: 2

    return 0;
}
