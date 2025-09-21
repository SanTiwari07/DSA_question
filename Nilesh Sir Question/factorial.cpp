#include<iostream>
using namespace std;
int factorial(int a){
    if(a == 0){
        return 1;
    }else{
        return (a)*factorial(a-1);
    }
}
int main(){
    int number;
    cout<<"Enter number: ";
    cin>>number;
    cout<<endl<<"Factorial of "<<number<<" is "<<factorial(number);

    return 0;
}
