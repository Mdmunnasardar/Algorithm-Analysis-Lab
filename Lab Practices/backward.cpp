#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void FGraph(vector<vector<int>>& c, int k, int n, vector<int>& path, vector<int>& cost) {
    vector<int> d(n, -1);     // d[i] = next vertex on the shortest path from i
    cost[n - 1] = 0;          // Cost to reach destination is 0

    // Backward computation of costs
   for (int j = n - 2; j >= 0; --j) {
    for (int i = 0; i < n; ++i) {
        if (c[j][i] != INF && cost[i] != INF && cost[j] > c[j][i] + cost[i]) {
            cost[j] = c[j][i] + cost[i];
            d[j] = i;
        }
    }
}


    // Reconstruct the path
    path[0] = 0;
    path[k - 1] = n - 1;
    for (int i = 1; i < k - 1; ++i) {
        path[i] = d[path[i - 1]];
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

    vector<int> path(k);
    vector<int> cost(n, INF); // Declare cost in main
    FGraph(c, k, n, path, cost);

    cout << "\nMinimum cost: " << cost[0] << endl;
    cout << "Optimal path: ";
    for (int stage : path) {
        cout << stage << " ";
    }
    cout << endl;

    return 0;
}
