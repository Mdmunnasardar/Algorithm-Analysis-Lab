#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int src, dest, weight;
};

void BellmanFord(int v, vector<Edge>& edges, int n) {
    vector<int> dist(n, INF);
    dist[v] = 0; // Source vertex distance = 0

    // Relax all edges (n-1) times
    for (int k = 1; k <= n - 1; ++k) {
        for (const Edge& e : edges) {
            if (dist[e.src] != INF && dist[e.dest] > dist[e.src] + e.weight) {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& e : edges) {
        if (dist[e.src] != INF && dist[e.dest] > dist[e.src] + e.weight) {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }

    // Print results
    cout << "Shortest distances from vertex " << v << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To " << i << ": ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int n, e, src;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges(e);
    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << "Enter source vertex: ";
    cin >> src;

    BellmanFord(src, edges, n);

    return 0;
} 