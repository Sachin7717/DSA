#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj_list;

public:
    void addEdge(int u, int v) {
        adj_list[u].push_back(v);
    }

    vector<int> bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;
        vector<int> reachable_nodes;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            reachable_nodes.push_back(node);

            for (int neighbor : adj_list[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return reachable_nodes;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int start_node = 2;
    vector<int> reachable_nodes = g.bfs(start_node);

    cout << "Nodes reachable from node " << start_node << ": ";
    for (int node : reachable_nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
