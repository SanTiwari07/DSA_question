#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int x) {
        data = x;
        next = nullptr;
    }
};

class circular_linked_list {
    node* head;

public:
    circular_linked_list() {
        head = nullptr;
    }

    void add(int val, int pos = -1) {
        node* newnode = new node(val);
        if (head == nullptr) {
            // First node points to itself
            newnode->next = newnode;
            head = newnode;
            return;
        }

        if (pos == 1) {
            // Insert at beginning
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;  // Last node points to new head
            head = newnode;
            return;
        }

        node* temp = head;
        int current_position = 1;
        while (temp->next != head && (pos == -1 || current_position < pos - 1)) {
            temp = temp->next;
            current_position++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void del(int val) {
        if (head == nullptr) return;

        // Deleting head node
        if (head->data == val) {
            if (head->next == head) {
                // Only one node
                delete head;
                head = nullptr;
            } else {
                node* temp = head;
                while (temp->next != head)
                    temp = temp->next; // Last node
                node* deleting_node = head;
                head = head->next;
                temp->next = head;
                delete deleting_node;
            }
            return;
        }

        // Deleting non-head node
        node* temp = head;
        while (temp->next != head && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << "Value not found\n";
            return;
        }

        node* deleting_node = temp->next;
        temp->next = temp->next->next;
        delete deleting_node;
    }

    void display() {
        if (head == nullptr) return;
        node* temp = head;
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    circular_linked_list list;
    list.add(0);
    list.add(10);
    list.add(20);
    list.display();
    list.del(0);
    list.display();
}
