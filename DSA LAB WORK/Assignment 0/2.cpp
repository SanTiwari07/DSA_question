#include<iostream>
using namespace std;

class sample{
    public:
    int number;
    void display(){
        cout<<"Number is "<<number<<endl;
    }
};

int main(){
    sample s;
    s.number = 90;
    s.display();

    return 0;
}