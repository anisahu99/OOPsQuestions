# include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define odd(n) (n&1)
#define even(n) !(n&1)

class Student{
    
    public:
    string name;
    int rollno;
    // A static member shared by all objects of the class
    static string schoolName; // School Name common for all students of that school

    // Static Method cannot use Non-static member of a class
    static void setSchoolName( string value ){
        // this->schoolName = value; // 'this' may only be used inside a nonstatic member function
        schoolName = value;
    }
};

string Student::schoolName ="TKIC"; 
int main(){
    Student s1;
    s1.schoolName = "LVIT";
    cout<<Student::schoolName<<endl;
    return 0;
}