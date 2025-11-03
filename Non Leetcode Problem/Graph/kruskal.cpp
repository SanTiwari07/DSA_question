#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For iota

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Custom comparison function for sorting edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// --- Disjoint Set Union (DSU) Implementation ---

// Find operation with path compression
int findParent(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}

// Union operation by rank/size
void uniteSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rootX != rootY) {
        // Attach smaller rank tree under root of high rank tree (Union by Rank)
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // If ranks are same, then make one as root and increment its rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Function to find the MST using Kruskal's Algorithm
void kruskalMST(int V, vector<Edge>& edges) {
    // 1. Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // DSU structure initialization
    vector<int> parent(V);
    // Initialize parent array: parent[i] = i
    iota(parent.begin(), parent.end(), 0); 
    vector<int> rank(V, 0);

    vector<Edge> result_mst; // Stores the edges in the resulting MST
    int mst_weight = 0;
    int edges_count = 0; // Count of edges added to MST (should be V-1)

    cout << "\nMST Edges (Kruskal's Algorithm):" << endl;

    // 2. Iterate through sorted edges
    for (const Edge& edge : edges) {
        // If we have V-1 edges, we are done
        if (edges_count == V - 1) {
            break;
        }

        int u = edge.src;
        int v = edge.dest;

        // Find the root parents of u and v
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        // 3. Check for cycle: If parents are different, adding this edge is safe
        if (rootU != rootV) {
            result_mst.push_back(edge); // Add the edge to MST
            mst_weight += edge.weight;
            edges_count++;

            // Union the sets (connect the two components)
            uniteSets(parent, rank, u, v);

            cout << "  Added: (" << u << " -- " << v << ") with weight " << edge.weight << endl;
        }
    }

    cout << "Total Minimum Spanning Tree Weight: " << mst_weight << endl;
}

int main() {
    cout << "--- Find the MST using Kruskal's Algorithm ---" << endl;

    // Example Graph (V=4, E=5)
    // Vertices are 0, 1, 2, 3
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    // Sort the edges for clarity in the output
    sort(edges.begin(), edges.end(), compareEdges);
    cout << "Initial Edges Sorted by Weight:" << endl;
    for (const auto& e : edges) {
        cout << "  (" << e.src << " -- " << e.dest << ") W: " << e.weight << endl;
    }

    kruskalMST(V, edges);

    return 0;
}
