//stack
//Stack (create, access, alter, loop through, insert, and delete).
#include<iostream>
#include<stack>
using namespace std;
class stacks{
    public:
    stack<string>cars ;
    void intialise(){
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }
    void display(){
        while(!cars.empty()){
            cout<<cars.top()<<" ";
            cars.pop();
        }
    }
    void access(){
        intialise();
        cout<<"Accessing top element: "<<cars.top()<<endl;
        display();
        cout<<endl;
    }
    void alteration(){
        intialise();
        cout<<"Changing top index to porsche"<<endl;
        cars.top()="porsche";
        display();
        cout<<endl;
    }
    void insertion(){
        intialise();
        cout<<"Adding rolls in end\n";
        cars.push("rolls");
        display();
        cout<<endl;
    }
    void deletion(){
        intialise();
        cout<<"Deleting the last element.\n";
        cars.pop();
        display();
        cout<<endl;
    }
};

int main(){
    stacks s;
    s.access();
    cout<<endl;
    s.alteration();
    cout<<endl;
    s.insertion();
    cout<<endl;
    s.deletion();
    cout<<endl;

    return 0;
}