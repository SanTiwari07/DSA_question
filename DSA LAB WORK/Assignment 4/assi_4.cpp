#include <iostream> 
#include <queue> 
#include <string> 
using namespace std; 
 
class ticket_booking_system { 
public: 
    queue<string> customer; 
 
    int number(string name) { 
        queue<string> temp = customer; 
        int count = 1; 
        while (!temp.empty()) { 
            if (temp.front() == name) return count; 
            temp.pop(); 
            count++; 
        } 
        return 0; 
    } 
 
    void add_customer(string name) { 
        customer.push(name); 
        cout << name << ", You have been added to queue.\n"; 
        cout << "You are at number " << number(name) << " in counter.\n"; 
    } 
 
    void process_customer(string name) { 
        if (customer.empty()) { 
            cout << "No customer\n"; 
        } else if(name == customer.front()) {
            cout << customer.front() << " has been served.\n"; 
            customer.pop(); 
        }else{ 
            if(number(name) == 0){ 
                cout<<name<<" is not there in list\n"; 
            }else{ 
                cout<<name<<", you are at "<<number(name)<<endl; 
            } 
        } 
    } 
 
    void display() { 
        queue<string> temp = customer; 
        int count = 1; 
        if (customer.empty()) { 
            cout << "No customer\n"; 
            return; 
        } 
        while (!temp.empty()) { 
            cout << count++ << ". " << temp.front() << "\n"; 
            temp.pop(); 
        } 
    } 
}; 
 
int main() { 
    ticket_booking_system t; 
    string name; 
    int choice; 
    cout << "Welcome to Booking System.\n"; 
    do { 
        cout << "\nDisplay Menu\n"; 
        cout << "1. Add Customer\n"; 
        cout << "2. Process Customer\n"; 
        cout << "3. Display Queue\n"; 
        cout << "4. Exit\n"; 
        cout << "\nEnter choice: ";
               cin >> choice; 
 
        switch (choice) { 
        case 1: 
            cout << "Enter name: "; 
            cin >> name; 
            t.add_customer(name); 
            break; 
        case 2: 
            cout << "Enter name: "; 
            cin >> name; 
            t.process_customer(name); 
            break; 
        case 3: 
            cout << "Display of the current list\n"; 
            t.display(); 
            break; 
        case 4: 
            break; 
        default: 
            cout << "Invalid choice! Try again.\n"; 
        } 
    } while (choice != 4); 
 
    return 0; 
} 