#include <iostream>
#include <vector>
using namespace std;

// Function to perform Warshall's algorithm
void warshallAlgorithm(const vector<vector<int>>& graph, int V) {
    // Initialize reachability matrix
    vector<vector<int>> reach(V);

    // Copy input adjacency matrix to reachability matrix
    for (int i = 0; i < V; i++) {
        reach[i] = graph[i];
    }

    // Apply Warshall's algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    cout << "Transitive closure matrix is:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;  // Number of vertices

    // Initialize adjacency matrix using vector of vectors
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };

    // Check if input graph is a square matrix
    if (graph.size() != V || graph[0].size() != V) {
        cout << "Error: Input graph is not a square matrix." << endl;
        return 1;
    }

    // Function call to calculate transitive closure
    warshallAlgorithm(graph, V);

    return 0;
}