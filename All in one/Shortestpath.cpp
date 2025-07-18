#include <iostream>
#include <climits>
using namespace std;

// Helper function to find the unvisited vertex with the smallest distance
int findMinVertex(int* distance, bool* visited, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}

// Dijkstra's algorithm
void dijkstra(int** edges, int n) {
    int* distance = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0; // Start from vertex 0

    for (int i = 0; i < n - 1; i++) {
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;

        for (int j = 0; j < n; j++) {
            if (edges[minVertex][j] != 0 && !visited[j]) {
                int dist = distance[minVertex] + edges[minVertex][j];
                if (dist < distance[j]) {
                    distance[j] = dist;
                }
            }
        }
    }

    // Output distances from source vertex 0
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " distance: " << distance[i] << endl;
    }

    delete[] distance;
    delete[] visited;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    // Create adjacency matrix
    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    // Take edge input
    cout << "Enter edges (format: source destination weight):" << endl;
    for (int i = 0; i < e; i++) {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight; // Since the graph is undirected
    }

    cout << "\nShortest distances from vertex 0:\n";
    dijkstra(edges, n);

    // Cleanup
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
