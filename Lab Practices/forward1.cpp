#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void ForwardGraph(vector<vector<int>> &c, int k, int n, vector<int> &path, vector<int> &cost)
{
    vector<int> pred(n, -1);
    
    
    cost[0] = 0;  // Set the cost of the source node to 0

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (c[i][j] != INF && cost[i] != INF && cost[j] > cost[i] + c[i][j])
            {
                cost[j] = cost[i] + c[i][j];  // Corrected cost[i][j] to c[i][j]
                pred[j] = i;
            }
        }
    }

    path[k - 1] = n - 1;
    for (int i = k - 2; i >= 0; --i)
    {
        path[i] = pred[path[i + 1]];
    }
}

int main()
{
    int n, k, e;
    cout << "Number of nodes and stages: ";
    cin >> n >> k;

    vector<vector<int>> c(n, vector<int>(n, INF));
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination cost):" << endl;
    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
    }

    vector<int> path(k), cost(n, INF);
    ForwardGraph(c, k, n, path, cost);

    cout << "\nMinimum cost: " << cost[n - 1] << endl;

    cout << "Optimal Path: ";
    for (int v : path)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
