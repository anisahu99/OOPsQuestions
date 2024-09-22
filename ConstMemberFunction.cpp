# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class ParentClass{
    private:
    int x;
    public:

    int getValue() const;
    

    void setValue( const int &x ){
        this->x = x;
    }
};

int ParentClass:: getValue() const {
    // setValue(3); --> it will give error because A non-const function can only be called by a non-const object, and a const function cannot call it.
    return this->x;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ParentClass object;
    object.setValue(5);
    cout<<object.getValue()<<endl;

    // const ParentClass object2; // const variable "object2" requires an initializer -- class "ParentClass" has no user-provided default constructor
    const ParentClass object3 = object; // it is permissible
    cout<<object3.getValue()<<endl;;

    return 0;
}