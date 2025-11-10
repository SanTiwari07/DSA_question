#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
using namespace std;

// ---------------- SET CLASS ----------------
class sets {
public:
    set<string> cars = {"BMW", "Audi", "omni", "Volvo"};

    void display() {
        for (auto &p : cars) {
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
        cars.insert("911");
        display();

        cout << "Deleting 911\n";
        cars.erase("911");
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

// ---------------- MAP CLASS ----------------
class maps {
public:
    map<string, int> human = {{"Narendra", 75}, {"Meloni", 56}, {"Putin", 70}, {"Kim", 45}};

    void display() {
        for (auto &p : human) {
            cout << p.first << " - " << p.second << endl;
        }
        cout << endl;
    }

    void access() {
        display();
        cout << "Accessing Narendra age: " << human.at("Narendra") << endl;
        cout << "Accessing Kim age: " << human.at("Kim") << endl;
    }

    void changes() {
        display();
        cout << "Changing Meloni age to 47\n";
        human["Meloni"] = 47;
        display();
    }

    void insertDelete() {
        display();
        cout << "Inserting Xi = 68\n";
        human.insert({"Xi", 68});
        display();
        cout << "Deleting Xi\n";
        human.erase("Xi");
        display();
    }
};

// ---------------- LIST CLASS ----------------
class lists {
public:
    list<string> cars = {"BMW", "Audi", "omni", "Volvo"};

    void display() {
        for (auto &a : cars) {
            cout << a << " ";
        }
        cout << endl;
    }

    void access() {
        display();
        cout << "Accessing front element: " << cars.front() << endl;
        cout << "Accessing back element: " << cars.back() << endl;
    }

    void alteration() {
        display();
        cout << "Changing index 2 to porsche" << endl;
        auto it = cars.begin();
        advance(it, 2);
        *it = "porsche";
        display();
        cout << endl;
    }

    void insertion() {
        display();
        cout << "Adding rolls at end\n";
        cars.push_back("rolls");
        display();
        cout << endl;
    }

    void deletion() {
        display();
        cout << "Deleting the last element.\n";
        cars.pop_back();
        display();
        cout << endl;
    }
};

// ---------------- QUEUE CLASS ----------------
class queues {
public:
    queue<string> cars;

    void initialise() {
        while (!cars.empty()) cars.pop();
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }

    void display() {
        queue<string> temp = cars; // make a copy
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void access() {
        initialise();
        cout << "Accessing front element: " << cars.front() << endl;
        display();
        cout << endl;
    }

    void alteration() {
        initialise();
        cout << "Changing front element to porsche" << endl;
        cars.front() = "porsche";
        display();
        cout << endl;
    }

    void insertion() {
        initialise();
        cout << "Adding rolls at end\n";
        cars.push("rolls");
        display();
        cout << endl;
    }

    void deletion() {
        initialise();
        cout << "Deleting the front element.\n";
        cars.pop();
        display();
        cout << endl;
    }
};

// ---------------- STACK CLASS ----------------
class stacks {
public:
    stack<string> cars;

    void initialise() {
        while (!cars.empty()) cars.pop();
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }

    void display() {
        stack<string> temp = cars; // make a copy
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void access() {
        initialise();
        cout << "Accessing top element: " << cars.top() << endl;
        display();
        cout << endl;
    }

    void alteration() {
        initialise();
        cout << "Changing top element to porsche" << endl;
        cars.top() = "porsche";
        display();
        cout << endl;
    }

    void insertion() {
        initialise();
        cout << "Adding rolls at top\n";
        cars.push("rolls");
        display();
        cout << endl;
    }

    void deletion() {
        initialise();
        cout << "Deleting the top element.\n";
        cars.pop();
        display();
        cout << endl;
    }
};

// ---------------- VECTOR CLASS ----------------
class vectors {
public:
    vector<string> cars = {"BMW", "Audi", "omni", "Volvo"};

    void display() {
        for (auto &a : cars) {
            cout << a << " ";
        }
        cout << endl;
    }

    void access() {
        display();
        cout << "Accessing front element: " << cars.front() << endl;
        cout << "Accessing back element: " << cars.back() << endl;
        cout << "Accessing index 2: " << cars.at(2) << endl;
    }

    void alteration() {
        display();
        cout << "Changing index 2 to porsche" << endl;
        cars[2] = "porsche";
        display();
        cout << endl;
    }

    void insertion() {
        display();
        cout << "Adding rolls at end\n";
        cars.push_back("rolls");
        display();
        cout << endl;
    }

    void deletion() {
        display();
        cout << "Deleting the last element.\n";
        cars.pop_back();
        display();
        cout << endl;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    int choice;
    do {
        cout << "\nMenu: 1.Set  2.Map  3.List  4.Queue  5.Stack  6.Vector  0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            sets ss;
            ss.access();
            ss.insertDelete();
            ss.uniquenessSort();
            break;
        }
        case 2: {
            maps m;
            m.access();
            m.changes();
            m.insertDelete();
            break;
        }
        case 3: {
            lists l;
            l.access();
            l.alteration();
            l.insertion();
            l.deletion();
            break;
        }
        case 4: {
            queues q;
            q.access();
            q.alteration();
            q.insertion();
            q.deletion();
            break;
        }
        case 5: {
            stacks s;
            s.access();
            s.alteration();
            s.insertion();
            s.deletion();
            break;
        }
        case 6: {
            vectors v;
            v.access();
            v.alteration();
            v.insertion();
            v.deletion();
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
