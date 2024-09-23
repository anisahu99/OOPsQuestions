# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class Cls{
    public:
    int x = 2;
    void show(){
        cout<<this->x<<endl;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Cls object,*pointer = &object;
    int Cls:: *ptr = &Cls::x; // Pointer to Data Member a;

    object.*ptr = 5;
    object.show();
    pointer->*ptr = 6;
    object.show();

    return 0;
}