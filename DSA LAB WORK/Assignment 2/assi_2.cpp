#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <string>
using namespace std;
#include <set>
class sets
{
public:
    set<string> cars = {"BMW", "Audi", "omni", "Volvo"};

    void display()
    {
        for (auto p : cars)
        {
            cout << p << endl;
        }
        cout << endl;
    }

    void access()
    {
        display();
        cout << "Accessing first element: " << *cars.begin() << endl;
        cout << "Accessing last element: " << *prev(cars.end()) << endl;
    }

    void insertDelete()
    {
        display();
        cout << "Inserting 911\n";
        cars.insert("911"); // add
        display();

        cout << "Deleting 911\n";
        cars.erase("911"); // remove
        display();
    }

    void uniquenessSort()
    {
        cout << "Trying to insert duplicate 'BMW' and new 'Alto'\n";
        cars.insert("BMW");
        cars.insert("Alto");
        display();
        cout << "Notice: Elements are unique and always sorted.\n";
    }
};
class maps
{
public:
    map<string, int> human = {{"Narendra", 75}, {"Meloni", 56}, {"Putin", 70}, {"Kim", 45}};
    void display()
    {
        for (auto &p : human)
        {
            cout << p.first << " - " << p.second << endl;
        }
        cout << endl;
    }
    void access()
    {
        display();
        cout << "Accessing Narendra age: " << human["Narendra"] << endl;
        cout << "Accessing Kim age: " << human["Kim"] << endl;
    }
    void changes()
    {
        display();
        cout << "Changing Meloni age to 47\n";
        human["Meloni"] = 47;
        display();
    }
    void insertDelete()
    {
        display();
        cout << "Inserting Xi = 68\n";
        human.insert({"Xi", 68});
        display();
        cout << "Deleting the Xi\n";
        human.erase("Xi");
        display();
    }
};
class lists
{
public:
    list<string> cars = {"BMW", "Audi", "omni", "Volvo"};
    void display()
    {
        for (auto a : cars)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    void access()
    {
        display();
        cout << "Accessing front element: " << cars.front() << endl;
        cout << "Accessing back element: " << cars.back() << endl;
    }
    void alteration()
    {
        display();
        cout << "Changing index 2 to porsche" << endl;
        auto it = cars.begin();
        advance(it, 2);  // move to index 2
        *it = "porsche"; // assign new value
        display();
        cout << endl;
    }
    void insertion()
    {
        display();
        cout << "Adding rolls in end\n";
        cars.push_back("rolls");
        display();
        cout << endl;
    }
    void deletion()
    {
        display();
        cout << "Deleting the last element.\n";
        cars.pop_back();
        display();
        cout << endl;
    }
};
class queues
{
public:
    queue<string> cars;
    void intialise()
    {
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }
    void display()
    {
        while (!cars.empty())
        {
            cout << cars.front() << " ";
            cars.pop();
        }
    }
    void access()
    {
        intialise();
        cout << "Accessing top element: " << cars.front() << endl;
        display();
        cout << endl;
    }
    void alteration()
    {
        intialise();
        cout << "Changing top index to porsche" << endl;
        cars.front() = "porsche";
        display();
        cout << endl;
    }
    void insertion()
    {
        intialise();
        cout << "Adding rolls in end\n";
        cars.push("rolls");
        display();
        cout << endl;
    }
    void deletion()
    {
        intialise();
        cout << "Deleting the last element.\n";
        cars.pop();
        display();
        cout << endl;
    }
};
class stacks
{
public:
    stack<string> cars;
    void intialise()
    {
        cars.push("BMW");
        cars.push("Audi");
        cars.push("omni");
        cars.push("Volvo");
    }
    void display()
    {
        while (!cars.empty())
        {
            cout << cars.top() << " ";
            cars.pop();
        }
    }
    void access()
    {
        intialise();
        cout << "Accessing top element: " << cars.top() << endl;
        display();
        cout << endl;
    }
    void alteration()
    {
        intialise();
        cout << "Changing top index to porsche" << endl;
        cars.top() = "porsche";
        display();
        cout << endl;
    }
    void insertion()
    {
        intialise();
        cout << "Adding rolls in end\n";
        cars.push("rolls");
        display();
        cout << endl;
    }
    void deletion()
    {
        intialise();
        cout << "Deleting the last element.\n";
        cars.pop();
        display();
        cout << endl;
    }
};
class vectors
{
public:
    vector<string> cars = {"BMW", "Audi", "omni", "Volvo"};
    void display()
    {
        for (auto a : cars)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    void access()
    {
        display();
        cout << "Accessing front element: " << cars.front() << endl;
        cout << "Accessing back element: " << cars.back() << endl;
        cout << "Accessing index 2: " << cars.at(2) << endl;
    }
    void alteration()
    {
        display();
        cout << "Changing index 2 to porsche" << endl;
        cars[2] = "porsche";
        display();
        cout << endl;
    }
    void insertion()
    {
        display();
        cout << "Adding rolls in end\n";
        cars.push_back("rolls");
        display();
        cout << endl;
    }
    void deletion()
    {
        display();
        cout << "Deleting the last element.\n";
        cars.pop_back();
        display();
        cout << endl;
    }
};
#include <iostream>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "\nMenu: 1.set  2.map  3.list  4.queue  5.stack  6.vector  0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            sets ss;
            ss.access();
            ss.insertDelete();
            ss.uniquenessSort();
            break;
        }
        case 2:
        {
            maps m;
            m.access();
            m.changes();
            m.insertDelete();
            break;
        }
        case 3:
        {
            lists l;
            l.access();
            cout << endl;
            l.alteration();
            cout << endl;
            l.insertion();
            cout << endl;
            l.deletion();
            cout << endl;
            break;
        }
        case 4:
        {
            queues q;
            q.access();
            cout << endl;
            q.alteration();
            cout << endl;
            q.insertion();
            cout << endl;
            q.deletion();
            cout << endl;
            break;
        }
        case 5:
        {
            stacks s;
            s.access();
            cout << endl;
            s.alteration();
            cout << endl;
            s.insertion();
            cout << endl;
            s.deletion();
            cout << endl;
            break;
        }
        case 6:
        {
            vectors v;
            v.access();
            cout << endl;
            v.alteration();
            cout << endl;
            v.insertion();
            cout << endl;
            v.deletion();
            cout << endl;
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
