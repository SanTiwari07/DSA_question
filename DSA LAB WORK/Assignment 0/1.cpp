#include<iostream>
using namespace std;

class sample{
    public:
    void greet(){
        cout<<"Hello World!";
    }
};
int main(){
    sample s;
    s.greet();
    int number;
    cout<<endl<<"Enter number: ";
    cin>>number;
    cout<<"number is "<<number;
    return 0;
}
