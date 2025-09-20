//Queue
//Queue (create, access, alter, loop through, insert, and delete).
#include<iostream>
#include<queue>
using namespace std;
class queues{
    public:
    queue<string>cars ;
    void intialise(){
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }
    void display(){
        while(!cars.empty()){
            cout<<cars.front()<<" ";
            cars.pop();
        }
    }
    void access(){
        intialise();
        cout<<"Accessing top element: "<<cars.front()<<endl;
        display();
        cout<<endl;
    }
    void alteration(){
        intialise();
        cout<<"Changing top index to porsche"<<endl;
        cars.front()="porsche";
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
    queues q;
    q.access();
    cout<<endl;
    q.alteration();
    cout<<endl;
    q.insertion();
    cout<<endl;
    q.deletion();
    cout<<endl;

    return 0;
}