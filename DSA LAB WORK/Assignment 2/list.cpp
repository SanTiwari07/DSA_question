//list
//List (create, access (front, back, at), alter, loop through, insert, and delete).
#include<iostream>
#include<list>
using namespace std;
class lists{
    public:
    list<string>cars = {"BMW","Audi","omni","Volvo"};
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
    }
    void alteration(){
        display();
        cout<<"Changing index 2 to porsche"<<endl;
        auto it = cars.begin();
        advance(it, 2);   // move to index 2
        *it = "porsche";  // assign new value
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
    lists l;
    l.access();
    cout<<endl;
    l.alteration();
    cout<<endl;
    l.insertion();
    cout<<endl;
    l.deletion();
    cout<<endl;

    return 0;
}