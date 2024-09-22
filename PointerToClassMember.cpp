# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)


class A{
    public:
    int x;

    A():x(0){}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    A obj;
    A *ptr = &obj;
    cout<<ptr<<endl;
    delete ptr;
    cout<<ptr->x<<endl;
/*
In this code, there is a critical mistake related to the use of delete on an object that was not dynamically allocated. This is the main catch, and it will lead to undefined behavior.

The delete operator is meant to be used for memory that was allocated dynamically using new.

In this case, since obj is allocated on the stack, using delete ptr; is invalid and results in undefined behavior. The delete operator is trying to free memory that wasn't allocated dynamically, which can crash your program or lead to unpredictable results.

*/

    return 0;
}