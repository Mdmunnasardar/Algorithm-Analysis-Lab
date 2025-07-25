#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void FGraphForward(vector<vector<int>>& c, int k, int n, vector<int>& path, vector<int>& cost) {
    vector<int> pred(n, -1);  // pred[i] = vertex before i on shortest path
    cost[0] = 0;              // Starting vertex has cost 0

    // Forward computation of costs
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (c[i][j] != INF && cost[i] != INF && cost[j] > cost[i] + c[i][j]) {
                cost[j] = cost[i] + c[i][j];
                pred[j] = i; // record predecessor
            }
        }
    }

    // Reconstruct path from source to destination
    path[k - 1] = n - 1;  // Last vertex
    for (int i = k - 2; i >= 0; --i) {
        path[i] = pred[path[i + 1]];
    }
}

int main() {
    int n, k, e;
    cout << "Enter number of vertices (n) and stages (k): ";
    cin >> n >> k;

    vector<vector<int>> c(n, vector<int>(n, INF));
    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination cost):\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
    }

    vector<int> path(k), cost(n, INF);
    FGraphForward(c, k, n, path, cost);

    // Output results
    cout << "\nMinimum cost: " << cost[n - 1] << endl;
    cout << "Optimal path: ";
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
