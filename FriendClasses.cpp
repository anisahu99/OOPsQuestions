# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

// this flaw of oops principle(Encapsulation)

class FriendA{
    private:
    int x = 1;
    friend class FriendB; // Friend Class
    public:
    int y = 2;

};

class FriendB{
    public:

    void displayFriendA(FriendA &object){
        cout<<object.x<<endl;
        cout<<object.y<<endl;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    FriendA a;
    FriendB b;
    b.displayFriendA(a);


    return 0;
}