#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class linked_list
{
public:
    node *head;
    void display() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
    linked_list()
    {
        head = NULL;
    }
    node *new_node(int num)
    {
        node *new_node = new node(num);
        new_node->next = head;
        head = new_node;
    }
    void insert_anywhere(int num, int pos)
    {
        node *new_node = new node(num);
        node *curr = head;
        node *prev = NULL;
        int count = 1;
        while (curr != NULL && count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (prev == NULL)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        prev->next = new_node;
        new_node->next = curr;
    }
    void insert_at_end(int num)
    {
        node *new_node = new node(num);
        if (head == NULL)
        {
            head = new_node;
        }
        if (head->next == NULL)
        {
            head->next = new_node;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void insert_at_start(int num)
    {
        node *new_node = new node(num);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    void delete_anywhere(int pos)
    {
        if (head = NULL)
        {
            cout << "List is empty!\n";
        }
        node *curr = head;
        node *prev = NULL;
        int count = 1;

        while (curr != NULL && count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        if (prev == NULL)
        {
            head = curr->next;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }
    }
    void delete_at_first(){
        if(head ==NULL){
            cout<<"Empty list!\n";
        }
        else{
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void delete_at_last(){
        if(head == NULL){
            cout<<"empty!\n";
        }
        if(head->next = NULL){
            delete head;
            head = NULL;
        }
        node* curr = head;
        node* prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }
};