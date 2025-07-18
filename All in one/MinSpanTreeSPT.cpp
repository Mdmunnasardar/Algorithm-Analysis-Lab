#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100; // max number of vertices

class Solution {
public:
    int spanningTree(int V, int adj[MAX][MAX]) {
        bool visited[MAX] = {false};
        // Min heap priority queue: pair<weight, node>
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> pq;
        
        pq.push({0, 0}); // Start from node 0 with weight 0
        int sum = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (visited[node]) continue;

            visited[node] = true;
            sum += wt;

            // Add all edges from current node to pq
            for (int adjNode = 0; adjNode < V; adjNode++) {
                if (adj[node][adjNode] != 0 && !visited[adjNode]) {
                    pq.push({adj[node][adjNode], adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    int adj[MAX][MAX] = {0}; // Initialize adjacency matrix to 0

    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;  // because graph is undirected
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights in MST: " << sum << endl;

    return 0;
}
