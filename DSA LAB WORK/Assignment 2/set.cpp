//set
//Set (create, access, add, remove, loop through, unique, and sort).
#include <iostream>
#include <set>
using namespace std;

class sets {
public:
    set<string> cars = {"BMW", "Audi", "omni", "Volvo"};

    void display() {
        for (auto p : cars) {
            cout << p << endl;
        }
        cout << endl;
    }

    void access() {
        display();
        cout << "Accessing first element: " << *cars.begin() << endl;
        cout << "Accessing last element: " << *prev(cars.end()) << endl;
    }

    void insertDelete() {
        display();
        cout << "Inserting 911\n";
        cars.insert("911");   // add
        display();

        cout << "Deleting 911\n";
        cars.erase("911");   // remove
        display();
    }

    void uniquenessSort() {
        cout << "Trying to insert duplicate 'BMW' and new 'Alto'\n";
        cars.insert("BMW");
        cars.insert("Alto");
        display();
        cout << "Notice: Elements are unique and always sorted.\n";
    }
};

int main() {
    sets ss;
    ss.access();
    ss.insertDelete();
    ss.uniquenessSort();
    return 0;
}
