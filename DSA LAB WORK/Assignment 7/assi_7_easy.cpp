#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class SocialNetwork {
    map<string, vector<string>> graph;   // person → list of friends

public:

    // Add a new person
    void addPerson(string name) {
        if (graph.count(name) == 0) {
            graph[name] = {};
            cout << name << " added.\n";
        } else {
            cout << name << " already exists.\n";
        }
    }

    // Add friendship between two people
    void addFriendship(string a, string b) {
        if (!graph.count(a) || !graph.count(b)) {
            cout << "Both people must exist.\n";
            return;
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
        cout << "Friendship created between " << a << " and " << b << ".\n";
    }

    // BFS → Print all connected people
    void findFriendsBFS(string start) {
        if (!graph.count(start)) {
            cout << "Person not found.\n";
            return;
        }

        map<string, bool> visited;
        queue<string> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            string person = q.front();
            q.pop();

            cout << person << " ";

            for (string friendName : graph[person]) {
                if (!visited[friendName]) {
                    visited[friendName] = true;
                    q.push(friendName);
                }
            }
        }
        cout << "\n";
    }

    // DFS helper function
    bool dfs(string a, string b, map<string, bool>& visited) {
        if (a == b) return true;
        visited[a] = true;

        for (string friendName : graph[a]) {
            if (!visited[friendName]) {
                if (dfs(friendName, b, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Check if two people are connected
    void checkConnectionDFS(string a, string b) {
        if (!graph.count(a) || !graph.count(b)) {
            cout << "Both people must exist.\n";
            return;
        }

        map<string, bool> visited;

        if (dfs(a, b, visited)) {
            cout << a << " and " << b << " are connected.\n";
        } else {
            cout << a << " and " << b << " are not connected.\n";
        }
    }

    // Show complete network
    void displayNetwork() {
        cout << "\nNetwork:\n";
        for (auto pair : graph) {
            cout << pair.first << " -> ";
            for (string f : pair.second) {
                cout << f << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    SocialNetwork sn;
    int choice;
    string p1, p2;

    while (true) {
        cout << "\n1. Add Person\n";
        cout << "2. Add Friendship\n";
        cout << "3. Find Friends (BFS)\n";
        cout << "4. Check Connection (DFS)\n";
        cout << "5. Display Network\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> p1;
            sn.addPerson(p1);
        }
        else if (choice == 2) {
            cout << "Enter first person: ";
            cin >> p1;
            cout << "Enter second person: ";
            cin >> p2;
            sn.addFriendship(p1, p2);
        }
        else if (choice == 3) {
            cout << "Enter name: ";
            cin >> p1;
            sn.findFriendsBFS(p1);
        }
        else if (choice == 4) {
            cout << "Enter first person: ";
            cin >> p1;
            cout << "Enter second person: ";
            cin >> p2;
            sn.checkConnectionDFS(p1, p2);
        }
        else if (choice == 5) {
            sn.displayNetwork();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}
