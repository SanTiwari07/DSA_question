//deque
#include<iostream>
#include<deque>
using namespace std;
class deques{
    public:
    deque<string>cars = {"BMW","Audi","omni","Volvo"};
    void display(){
        for(auto a : cars){
            cout<<a<<" ";
        }
        cout<<endl;
    }
    void access(){
        display();
        cout<<"Accessing front element: "<<cars.front()<<endl;
        cout<<"Accessing back element: "<<cars.back()<<endl;
        cout<<"Accessing index 2: "<<cars.at(2)<<endl;
    }
    void alteration(){
        display();
        cout<<"Changing index 2 to porsche"<<endl;
        cars[2]="porsche";
        display();
        cout<<endl;
    }
    void insertion(){
        display();
        cout<<"Adding rolls in end\n";
        cars.push_back("rolls");
        display();
        cout<<endl;
    }
    void deletion(){
        display();
        cout<<"Deleting the last element.\n";
        cars.pop_back();
        display();
        cout<<endl;
    }
};

int main(){
    deques d;
    d.access();
    cout<<endl;
    d.alteration();
    cout<<endl;
    d.insertion();
    cout<<endl;
    d.deletion();
    cout<<endl;

    return 0;
}