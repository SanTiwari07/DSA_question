#include<iostream>
using namespace std;

class math_operation{
    private:
    int num1;
    int num2;

    public:
    math_operation(int x , int y){
        num1=x;
        num2=y;
    }
    int add(){
        return num1+num2;
    }
    int mul(){
        return num1*num2;
    }
    int div(){
        return num1/num2;
    }
};

int main(){
    int a,b;
    cout<<"Enter number 1: ";
    cin>>a;
    cout<<"Enter number 2: ";
    cin>>b;

    math_operation m(a,b);

    int cases;
    cout<<"0 for addition\n1 for multiplication\n2 for division\n";
    cin>>cases;
    switch(cases){
        case 0:
        cout<<m.add();
        break;

        case 1:
        cout<<m.mul();
        break;

        case 2:
        cout<<m.div();
        break;
    }
    
    return 0;
}