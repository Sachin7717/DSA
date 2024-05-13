#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // pair of (weight, vertex)

void primMST(vector<vector<pii>>& graph) {
    int V = graph.size();
    vector<int> parent(V, -1); // to store MST
    vector<int> key(V, INT_MAX); // to store minimum weight edge

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap (weight, vertex)

    key[0] = 0; // Start from the first vertex
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (weight < key[v] && (parent[v] == -1 || (parent[v] != -1 && parent[v] == u))) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    // Print MST
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pii>> graph(V); // graph represented as adjacency list of (vertex, weight) pairs

    cout << "Enter edges (from, to, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // undirected graph
    }

    primMST(graph);

    return 0;
}
