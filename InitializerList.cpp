# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class A{
    public:
    const int x;
    int &reference;

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    A obj;
    
    return 0;
}

/*

The above code will result in a compilation error due to the following issues:

    Uninitialized const member:
        In class A, the member variable const int x is declared as const. In C++, all const members must be initialized when the object is constructed. However, in your class A, no constructor is provided to initialize x. This will cause a compilation error because const variables need to be initialized in the constructor initializer list.

    Uninitialized reference member:
        The reference member int &reference must also be initialized when an object of class A is created. Like const members, reference members must be initialized in the constructor initializer list. Since no constructor is provided to initialize the reference reference, this will also result in a compilation error.

To fix the errors, you need to provide a constructor for the class A that initializes both x and reference. Here's how you can modify the code:

*/

/*
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class A {
    public:
    const int x;      // Const member
    int &reference;   // Reference member

    // Constructor to initialize 'x' and 'reference'
    A(int _x, int &ref) : x(_x), reference(ref){}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int value = 10;
    A obj(5, value);  // Initializing 'x' and 'reference'

    cout << "x: " << obj.x << endl;          // Output: x: 5
    cout << "reference: " << obj.reference << endl;  // Output: reference: 10
    
    value = 20;       // Changing the value of 'reference'
    cout << "reference: " << obj.reference << endl;  // Output: reference: 20

    return 0;
}


*/
