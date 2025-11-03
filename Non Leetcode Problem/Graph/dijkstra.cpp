#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits> // For numeric_limits

using namespace std;

// Infinity value for initialization
const int INF = numeric_limits<int>::max();

// Function to find the shortest path from a source node to all other nodes
void dijkstra(int V, const vector<vector<pair<int, int>>>& adj, int startNode) {
    // 1. Initialize distances
    // dist[i] will hold the shortest distance from startNode to i
    vector<int> dist(V, INF); 
    
    // Parent array to reconstruct the path
    vector<int> parent(V, -1); 

    // Distance to the starting node is 0
    dist[startNode] = 0;

    // Priority Queue: Stores pairs of (distance, node).
    // The queue automatically orders elements, prioritizing the smallest distance.
    // The 'greater' template argument makes it a min-heap.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with the source node: (distance, node)
    pq.push({0, startNode});

    while (!pq.empty()) {
        // Extract the node 'u' with the minimum distance
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If a shorter path to 'u' has already been processed, skip
        if (d > dist[u]) {
            continue;
        }

        // 2. Iterate through all neighbors 'v' of 'u'
        for (const auto& edge : adj[u]) {
            int v = edge.first;     // Neighbor node
            int weight = edge.second; // Edge weight (u -> v)

            // 3. Relaxation step
            // If a shorter path to 'v' is found through 'u'
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; // Update distance
                parent[v] = u;              // Update parent for path tracking
                pq.push({dist[v], v});      // Add to priority queue
            }
        }
    }

    // Output the results
    cout << "\nShortest Distances from Node " << startNode << ":" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "  To Node " << i << ": ";
        if (dist[i] == INF) {
            cout << "Unreachable" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}

int main() {
    cout << "--- Shortest Distance Path using Dijkstra's Algorithm ---" << endl;

    // Example Graph (V=5)
    // Node 0 -> A, 1 -> B, 2 -> C, 3 -> D, 4 -> E
    int V = 5;
    // Adjacency list: vector of vectors of pairs (neighbor, weight)
    vector<vector<pair<int, int>>> adj(V);

    // Edges (Directed for simplicity, adjust for undirected)
    adj[0].push_back({1, 10}); // A -> B, weight 10
    adj[0].push_back({3, 5});  // A -> D, weight 5
    adj[1].push_back({2, 1});  // B -> C, weight 1
    adj[1].push_back({3, 2});  // B -> D, weight 2
    adj[2].push_back({4, 4});  // C -> E, weight 4
    adj[3].push_back({1, 3});  // D -> B, weight 3
    adj[3].push_back({2, 9});  // D -> C, weight 9
    adj[3].push_back({4, 2});  // D -> E, weight 2
    adj[4].push_back({0, 7});  // E -> A, weight 7 (Note: not reachable in path)
    
    int startNode = 0; // Start at node A
    dijkstra(V, adj, startNode);

    return 0;
}
