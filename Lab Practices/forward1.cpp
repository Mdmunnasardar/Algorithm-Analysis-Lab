#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void Forwargraph(vector<vector<int>> &c, int k, int n, vector<int> &path, vector<int> &cost)
{

    vector<int> pred(n, -1); // pred[i] = previous vertex on the shortest path to i
    cost[0] = 0;

    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (c[i][j] != INF && cost[i] != INF && cost[j] > cost[i] + c[i][j])
            {
                cost[j] = cost[i] + c[i][j];
                pred[j] = i;
            }
        
    }
}

path[k - 1] = n - 1;
for (int i = k - 2; i >= 0; i--)
{
    path[i] = pred[path[i + 1]];
}
path[0] = 0; 
}

int main()
{
    int n, k, e;

    cout << "Enter Number of nodes and Stages : ";
    cin >> n >> k;

    vector<vector<int>> c(n, vector<int>(n, INF));
    cout << " Enter the number of edges: ";
    cin >> e;
    // vector<vector<int>> c(n, vector<int>(n, INF));
    cout << "Enter edges (source destination cost): " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
    }

    vector<int> path(k), cost(n, INF);

    Forwargraph(c, k, n, path, cost);

    cout << "Minimum Cost : " <<cost[n-1]<< endl;

    cout << "Optimal path: " << endl;

    for (int v : path)
    {
        cout << v << " " << endl;
    }
    return 0;
}