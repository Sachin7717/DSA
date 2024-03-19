#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Graph represented as adjacency list
vector<vector<pair<int, int>>> graph; // Each element: (destination vertex, weight)

vector<int> dijkstra(int source) {
    int numVertices = graph.size();
    vector<int> dist(numVertices, INF); // Initialize distances to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        // Ignore outdated entries in priority queue
        if (u_dist > dist[u]) continue;

        // Relax edges
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    graph.resize(numVertices);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        // Assuming undirected graph
        graph[v].push_back({u, weight});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> shortestDistances = dijkstra(source);

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
