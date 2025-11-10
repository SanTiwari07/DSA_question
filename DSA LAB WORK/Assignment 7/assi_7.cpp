#include<unordered_map>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

class SocialNetwork{
    unordered_map<string, vector<string>> adjList;

public:
    void addPerson(string name){
        if(adjList.find(name) == adjList.end()){
            adjList[name] = {};
            cout<<name<<" added to the network."<<endl;
        } 
        else{
            cout<<name<<" already exists."<<endl;
        }
    }

    void addFriendship(string p1, string p2){
        if(adjList.find(p1) == adjList.end() || adjList.find(p2) == adjList.end()){
            cout<<"Both persons must exist."<<endl;
            return;
        }
        adjList[p1].push_back(p2);
        adjList[p2].push_back(p1);
        cout<<"Friendship created between"<<p1<<" and "<<p2<<"."<<endl;
    }

    void findFriendsBFS(string start){
        if(adjList.find(start) == adjList.end()){
            cout<<"Person not found."<<endl;
            return;
        }
        unordered_map<string, int> vis;
        queue<string>q;
        vis[start] = 1;
        q.push(start);
        cout<<"Friends (BFS): ";
        while(!q.empty()){
            string p = q.front();
            q.pop();
            cout<<p<<" ";
            for(auto &f : adjList[p]){
                if(!vis[f]){
                    vis[f] = 1;
                    q.push(f);
                }
            }
        }
        cout<<endl;
    }

    int dfsUtil(string s, string t, unordered_map<string, int> &vis){
        if(s == t){
            return 1;
        }
        vis[s] = 1;
        for(auto &f : adjList[s]){
            if(!vis[f]){
                if(dfsUtil(f, t, vis)){
                    return 1;
                }
            }
        }
        return 0;
    }

    void checkConnectionDFS(string p1, string p2){
        if(adjList.find(p1) == adjList.end() || adjList.find(p2) == adjList.end()){
            cout<<"Both persons must exist."<<endl;
            return;
        }
        unordered_map<string, int> vis;
        int connected = dfsUtil(p1, p2, vis);
        if(connected){
            cout<<p1<<" and "<<p2<<" are connected."<<endl;
        }
        else{
            cout<<p1<<" and "<<p2<<" are not connected."<<endl;
        }
    }

    void displayNetwork(){
        cout<<endl<<"Social Network:"<<endl;
        for(auto &p : adjList){
            cout<<p.first<<" -> ";
            for(auto &f : p.second){
                cout<<f<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    SocialNetwork sn;
    int ch;
    string p1, p2;
    while(1){
        cout<<endl;
        cout<<"1. Add Person"<<endl;
        cout<<"2. Add Friendship"<<endl;
        cout<<"3. Find Friends (BFS)"<<endl;
        cout<<"4. Check Connection (DFS)"<<endl;
        cout<<"5. Display Network"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>ch;

        if(ch == 1){
            cout<<"Enter name: ";
            cin>>p1;
            sn.addPerson(p1);
        } 
        else if(ch == 2){
            cout<<"Enter first person: ";
            cin>>p1;
            cout<<"Enter second person: ";
            cin>>p2;
            sn.addFriendship(p1, p2);
        } 
        else if(ch == 3){
            cout<<"Enter name: ";
            cin>>p1;
            sn.findFriendsBFS(p1);
        } 
        else if(ch == 4){
            cout<<"Enter first person: ";
            cin>>p1;
            cout<<"Enter second person: ";
            cin>>p2;
            sn.checkConnectionDFS(p1, p2);
        } 
        else if(ch == 5){
            sn.displayNetwork();
        }
        else if(ch == 6){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}