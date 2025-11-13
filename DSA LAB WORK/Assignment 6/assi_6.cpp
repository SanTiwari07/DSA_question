#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
    Student *left, *right;
};

class BST {
    Student* root;

    // Create new node
    Student* createNode(int r, string n, float m) {
        Student* s = new Student;
        s->roll = r;
        s->name = n;
        s->marks = m;
        s->left = s->right = NULL;
        return s;
    }

    // Recursive Insert
    Student* insertRec(Student* node, int r, string n, float m) {
        if (node == NULL)
            return createNode(r, n, m);

        if (r < node->roll)
            node->left = insertRec(node->left, r, n, m);
        else if (r > node->roll)
            node->right = insertRec(node->right, r, n, m);
        else
            cout << "Duplicate Roll not allowed!\n";

        return node;
    }

    // Recursive Search
    Student* searchRec(Student* node, int r) {
        if (node == NULL || node->roll == r)
            return node;

        if (r < node->roll)
            return searchRec(node->left, r);
        
        return searchRec(node->right, r);
    }

    // Find minimum node (for deletion)
    Student* findMin(Student* node) {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    // Recursive Delete
    Student* deleteRec(Student* node, int r) {
        if (node == NULL)
            return node;

        if (r < node->roll)
            node->left = deleteRec(node->left, r);
        else if (r > node->roll)
            node->right = deleteRec(node->right, r);
        else {
            // One or zero child
            if (node->left == NULL) {
                Student* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Student* temp = node->left;
                delete node;
                return temp;
            }

            // Two children
            Student* temp = findMin(node->right);
            node->roll = temp->roll;
            node->name = temp->name;
            node->marks = temp->marks;

            node->right = deleteRec(node->right, temp->roll);
        }

        return node;
    }

    // Recursive Traversals
    void inorderRec(Student* node) {
        if (node == NULL)
            return;

        inorderRec(node->left);
        cout << node->roll << " " << node->name << " (" << node->marks << ")\n";
        inorderRec(node->right);
    }

    void preorderRec(Student* node) {
        if (node == NULL)
            return;

        cout << node->roll << " " << node->name << " (" << node->marks << ")\n";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Student* node) {
        if (node == NULL)
            return;

        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->roll << " " << node->name << " (" << node->marks << ")\n";
    }

    // Non-recursive Inorder using stack
    void inorderNonRec() {
        stack<Student*> st;
        Student* curr = root;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            cout << curr->roll << " " << curr->name << " (" << curr->marks << ")\n";

            curr = curr->right;
        }
    }

    // Find highest & lowest marks
    void findHighLow(Student* node, float &high, float &low) {
        if (node == NULL)
            return;

        if (node->marks > high) high = node->marks;
        if (node->marks < low) low = node->marks;

        findHighLow(node->left, high, low);
        findHighLow(node->right, high, low);
    }

    // Count nodes
    int countRec(Student* node) {
        if (node == NULL)
            return 0;

        return 1 + countRec(node->left) + countRec(node->right);
    }

public:

    BST() { root = NULL; }

    void insert(int r, string n, float m) {
        root = insertRec(root, r, n, m);
    }

    void del(int r) {
        root = deleteRec(root, r);
    }

    void search(int r) {
        Student* s = searchRec(root, r);
        if (s != NULL)
            cout << "Found: " << s->roll << " " << s->name << " " << s->marks << endl;
        else
            cout << "Not found!\n";
    }

    void displayAll() {
        cout << "\nInorder (Recursive):\n";
        inorderRec(root);

        cout << "\nPreorder (Recursive):\n";
        preorderRec(root);

        cout << "\nPostorder (Recursive):\n";
        postorderRec(root);

        cout << "\nInorder (Non-Recursive):\n";
        inorderNonRec();
    }

    void highLowMarks() {
        if (root == NULL) {
            cout << "No records!\n";
            return;
        }

        float high = -1, low = 9999;
        findHighLow(root, high, low);

        cout << "\nHighest Marks: " << high;
        cout << "\nLowest Marks: " << low << endl;
    }

    void totalStudents() {
        cout << "Total Students: " << countRec(root) << endl;
    }
};

int main() {
    BST b;
    int ch;

    do {
        cout << "\n--- Student Database (BST) ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Highest & Lowest Marks\n6. Total Students\n0. Exit\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            int r; string n; float m;
            cout << "Enter Roll, Name, Marks: ";
            cin >> r >> n >> m;
            b.insert(r, n, m);
        }
        else if (ch == 2) {
            int r; 
            cout << "Enter Roll to delete: "; 
            cin >> r;
            b.del(r);
        }
        else if (ch == 3) {
            int r; 
            cout << "Enter Roll to search: "; 
            cin >> r;
            b.search(r);
        }
        else if (ch == 4)
            b.displayAll();
        else if (ch == 5)
            b.highLowMarks();
        else if (ch == 6)
            b.totalStudents();

    } while (ch != 0);

    cout << "Exiting...\n";
    return 0;
}
