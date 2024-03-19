#include <iostream>
using namespace std;

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];

void transitiveClosure(int n) {
    // Apply Warshall's algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (0/1):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    transitiveClosure(n);
    
    // Output transitive closure matrix
    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout <<endl;
    }

    return 0;
}
