//map
// Map (create, access, alter, loop through, insert, and delete).
#include<iostream>
#include<map>
#include<string>
using namespace std;
class maps{
    public:
    map<string,int>human={{"Narendra",75},{"Meloni",56},{"Putin",70},{"Kim",45}};
    void display(){
        for(auto &p : human){
            cout<<p.first<<" - "<<p.second<<endl;
        }
        cout<<endl;
    }
    void access(){
        display();
        cout<<"Accessing Narendra age: "<<human["Narendra"]<<endl;
        cout<<"Accessing Kim age: "<<human["Kim"]<<endl;
    }
    void changes(){
        display();
        cout<<"Changing Meloni age to 47\n";
        human["Meloni"]=47;
        display();
    }
    void insertDelete() {
        display();
        cout << "Inserting Xi = 68\n";
        human.insert({"Xi", 68});
        display();
        cout<<"Deleting the Xi\n";
        human.erase("Xi");
        display();
    }
};

int main(){
    maps m;
    m.access();
    m.changes();
    m.insertDelete();
    return 0;

}