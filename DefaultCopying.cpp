# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class Person{
    public:
    int x, y;
    void display(){
        cout<<x<<", "<<y<<endl;
    }
    
    Person(){
        cout<<"Hello"<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Person p1;
    p1.x =1;
    p1.y =2;

    // There are two ways to copy
    Person p2 = p1;
    Person p3(p1);
    Person p4{p1};
    p2.display();
    p3.display();
    p4.display();

    return 0;
}