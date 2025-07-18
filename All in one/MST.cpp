#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

class Solution {
public:
    void spanningTree(int V, int adj[MAX][MAX]) {
        bool visited[MAX] = {false};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int parent[MAX];

        for (int i = 0; i < V; i++)
            parent[i] = -1;

        parent[0] = 0;  // Starting from node 0
        pq.push({0, 0});

        cout << "Edges and Weights:\n";
        cout << "------------------\n";

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int i = it.second;  // current node

            if (visited[i]) continue;

            visited[i] = true;

            cout << parent[i] << " - " << i << " : " << wt << "\n";

            for (int j = 0; j < V; j++) {
                if (adj[i][j] != 0 && !visited[j]) {
                    pq.push({adj[i][j], j});
                    if (parent[j] == -1 || adj[i][j] < adj[parent[j]][j])
                        parent[j] = i;
                }
            }
        }

        cout << "------------------\n";
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    int adj[MAX][MAX] = {0};

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    Solution obj;
    obj.spanningTree(V, adj);

    return 0;
}
