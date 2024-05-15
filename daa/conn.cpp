#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

bool isConnected(vector<vector<int>>& graph, int order) {
    vector<bool> visited(order, false);
    dfs(graph, 0, visited);
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}

int main() {
    int order, size;
    cout << "Enter the order (number of vertices) of the graph: ";
    cin >> order;
    cout << "Enter the size (number of edges) of the graph: ";
    cin >> size;

    vector<vector<int>> graph(order);
    cout << "Enter the edges:" << endl;
    for (int i = 0; i < size; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming undirected graph
    }

    bool connected = isConnected(graph, order);
    if (connected) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
