#include <iostream>
using namespace std;
class stack
{
public:
    int top = -1;
    int arr[5];
    bool isfull()
    {
        if (top == sizeof(arr) - 1)
            return true;
        else
            return false;
    }
    bool islow()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    void push(int num)
    {
        if (isfull())
        {
            cout << "Error! We cannot inert.\n";
        }
        else
            arr[++top] = num;
    }
    void pop()
    {
        if (islow())
        {
            cout << "Error! We cannot remove.\n";
        }
        else
        {
            cout << "Removed element: " << arr[top];
            top--;
        }
    }
    void display(){
        cout<<endl;
        for(int a = 0 ; a <= top ; a++){
            cout<<arr[a]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    stack s;
    s.push(50);
    s.push(25);
    s.pop();
    s.display();
}