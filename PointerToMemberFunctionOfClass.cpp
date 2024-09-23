# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class Cls{
    public:

    int func( string str ){
        cout<<str<<endl;
        return 0;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int (Cls::*ptr)(string) = &Cls :: func ;

    Cls object;
    (object.*ptr)("d");


    return 0;
}