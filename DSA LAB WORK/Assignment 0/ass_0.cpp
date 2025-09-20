#include <iostream>
using namespace std;

class Array_Operation {
private:
    int arr[5];  // fixed-size array

public:
    // Constructor to initialize array elements
    Array_Operation() {
        arr[0] = 34;
        arr[1] = 21;
        arr[2] = 56;
        arr[3] = 78;
        arr[4] = 90;
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void access() {
        cout<<"Accessing 2th index: "<<arr[2];
    }

    void alter() {
        cout<<"Initial 3th index: "<<arr[3];
        cout<<endl<<"Changing to 9999\n";
        arr[3]=9999;
        display();
    }
    
};

int main() {
    Array_Operation obj;

    obj.display();    
    obj.access();   
    cout<<endl;    
    obj.alter();   
    obj.display();       

    return 0;
}
