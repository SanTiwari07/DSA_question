#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Structure for a student node in the BST
struct Student {
    int roll;
    string name;
    float marks;
    Student* left;
    Student* right;
};

// Class implementing the Binary Search Tree
class BST {
private:
    Student* root;

public:
    // Constructor
    BST() {
        root = NULL;
    }

    // Helper to create a new student node
    Student* createNode(int roll, string name, float marks) {
        Student* newNode = new Student();
        newNode->roll = roll;
        newNode->name = name;
        newNode->marks = marks;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Recursive insertion of student by roll number
    Student* insert(Student* node, int roll, string name, float marks) {
        if (node == NULL)
            return createNode(roll, name, marks);
        if (roll < node->roll)
            node->left = insert(node->left, roll, name, marks);
        else if (roll > node->roll)
            node->right = insert(node->right, roll, name, marks);
        else
            cout << "Duplicate Roll Number not allowed!\n";
        return node;
    }

    // Public method to insert a student
    void insertStudent(int roll, string name, float marks) {
        root = insert(root, roll, name, marks);
    }

    // Recursive search for a student by roll number
    Student* search(Student* node, int roll) {
        if (node == NULL || node->roll == roll)
            return node;
        if (roll < node->roll)
            return search(node->left, roll);
        else
            return search(node->right, roll);
    }

    // Public method to search and display a student
    void searchStudent(int roll) {
        Student* res = search(root, roll);
        if (res)
            cout << "Found -> Roll: " << res->roll << ", Name: " << res->name << ", Marks: " << res->marks << endl;
        else
            cout << "Student not found!\n";
    }

    // Find the minimum node (used in delete for in-order successor)
    Student* findMin(Student* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    // Recursive deletion of student by roll number
    Student* deleteNode(Student* node, int roll) {
        if (node == NULL)
            return node;

        if (roll < node->roll)
            node->left = deleteNode(node->left, roll);
        else if (roll > node->roll)
            node->right = deleteNode(node->right, roll);
        else {
            // Case 1 & 2: one or no child
            if (node->left == NULL) {
                Student* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Student* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: two children - replace with in-order successor (min in right subtree)
            Student* temp = findMin(node->right);
            node->roll = temp->roll;
            node->name = temp->name;
            node->marks = temp->marks;
            node->right = deleteNode(node->right, temp->roll);
        }
        return node;
    }

    // Public method to delete a student
    void deleteStudent(int roll) {
        root = deleteNode(root, roll);
    }

    // Recursive Inorder Traversal (Sorted order by Roll Number)
    void inorder(Student* node) {
        if (node) {
            inorder(node->left);
            cout << node->roll << " (" << node->name << ", " << node->marks << ")\n";
            inorder(node->right);
        }
    }

    // Recursive Preorder Traversal
    void preorder(Student* node) {
        if (node) {
            cout << node->roll << " (" << node->name << ", " << node->marks << ")\n";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Recursive Postorder Traversal
    void postorder(Student* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->roll << " (" << node->name << ", " << node->marks << ")\n";
        }
    }

    // Non-recursive Inorder Traversal using a stack
    void inorderNonRecursive() {
        stack<Student*> s;
        Student* curr = root;
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->roll << " (" << curr->name << ", " << curr->marks << ")\n";
            curr = curr->right;
        }
    }

    // Recursive helper to find highest and lowest marks
    void findHighestLowest(Student* node, float &high, float &low) {
        if (node == NULL)
            return;
        if (node->marks > high) high = node->marks;
        if (node->marks < low) low = node->marks;
        findHighestLowest(node->left, high, low);
        findHighestLowest(node->right, high, low);
    }

    // Public method to display highest and lowest marks
    void displayHighestLowest() {
        if (root == NULL) {
            cout << "No records!\n";
            return;
        }
        // Initialize high to a very low value and low to a very high value
        float high = -1;
        float low = 9999;
        findHighestLowest(root, high, low);
        cout << "Highest Marks: " << high << endl;
        cout << "Lowest Marks: " << low << endl;
    }

    // Recursive helper to count total nodes (students)
    int countNodes(Student* node) {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Public method to display total students
    void totalStudents() {
        cout << "Total Students: " << countNodes(root) << endl;
    }

    // Display menu options and handle user interaction
    void menu() {
        int ch;
        do {
            cout << "\n--- Student Database Menu ---\n";
            cout << "1. Insert Student\n2. Delete Student\n3. Search Student\n";
            cout << "4. Display (Inorder)\n5. Display (Preorder)\n6. Display (Postorder)\n";
            cout << "7. Display (Inorder Non-Recursive)\n";
            cout << "8. Highest & Lowest Marks\n9. Total Students\n0. Exit\n";
            cout << "Enter your choice: ";
            cin >> ch;
            
            if (ch == 1) {
                int r; string n; float m;
                cout << "Enter Roll, Name, Marks: ";
                cin >> r >> n >> m;
                insertStudent(r, n, m);
            }
            else if (ch == 2) {
                int r;
                cout << "Enter Roll to delete: ";
                cin >> r;
                deleteStudent(r);
            }
            else if (ch == 3) {
                int r;
                cout << "Enter Roll to search: ";
                cin >> r;
                searchStudent(r);
            }
            else if (ch == 4)
                inorder(root);
            else if (ch == 5)
                preorder(root);
            else if (ch == 6)
                postorder(root);
            else if (ch == 7)
                inorderNonRecursive();
            else if (ch == 8)
                displayHighestLowest();
            else if (ch == 9)
                totalStudents();
        } while (ch != 0);
        cout << "Exiting..." << endl;
    }
};

int main() {
    BST obj;
    obj.menu();
    return 0;
}