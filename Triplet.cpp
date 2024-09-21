# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

struct Triplet
{
    int first, second, third;

    

    Triplet(){
        this->first = this->second = this->third = 0;
    }
    Triplet(const int &x, const int &y, const int &z) const {
        this->first = x;
        this->second = y;
        this->third = z;
    }

    void display(){
        cout<<this->first<<", "<<this->second<<", "<<this->third<<endl;
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Triplet *t = new Triplet(1,2,3);
    t->display();

    return 0;
}