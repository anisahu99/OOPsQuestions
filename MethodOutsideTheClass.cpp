# include<iostream>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class Calculator{
    public:
    Calculator(); // Constructor Declaration
    int addTwoNumber( const int &x, const int &y ); // Method Declaration
};

Calculator::Calculator(){
cout<<"Hello"<<endl;
}
int Calculator::addTwoNumber(const int &x, const int &y){ // Method Definition Outside the Class
    return x+y;
}


int main(){
    Calculator c;
    cout<<c.addTwoNumber(2,3)<<endl;
    return 0;
}