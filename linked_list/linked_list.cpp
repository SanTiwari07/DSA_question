#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class linked_list
{
    node *head;

public:
    linked_list()
    {
        head = nullptr;
    }
    void add(int val, int pos = -1)
    {
        node *newnode = new node(val);
        if (head == NULL || pos == 1)
        {
            newnode->next = head;
            head = newnode;
            return;
        }

        node *temp = head;
        int current_position = 1;

        while (temp->next != NULL && (pos == -1 || current_position < pos - 1))
        {
            temp = temp->next;
            current_position++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void del(int val)
    {
        if (head == nullptr)
            return;
        if (head->data == val)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node *temp = head;
        while (temp->next != nullptr && temp->next->data != val)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Value not found\n";
            return;
        }
        node *deleting_node = temp->next;
        temp->next = temp->next->next;
        delete deleting_node;
    }
    void display()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    linked_list list;
    list.add(0);
    list.add(10);
    list.add(20);
    list.display();
    list.del(0);
    list.display();
}