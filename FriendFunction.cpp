# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class FriendA; // forward definition needed
// FriendB class in which function is declared

class FriendB{

    public:
    void showA(FriendA &object);
};

// FriendA class for which friend is declared
class FriendA{
    private:
    int x;
    
    public:
    FriendA():x(1){
    }

    friend void Hello(FriendA &object); // Friend Function -->Global Function
    friend void FriendB::showA(FriendA &object);  // Friend Function -->Method of another class
};


// friend function definition
void FriendB::showA(FriendA &object){
        cout<<object.x<<endl;
    }
void Hello(FriendA &object){
    cout<<object.x<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    FriendA object;
    FriendB object2;
    object2.showA(object);
    Hello(object);

    return 0;
}