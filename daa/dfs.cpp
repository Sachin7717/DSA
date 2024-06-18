#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[v] = true; 
    cout << v << " ";  

    for (int u : adjList[v]) {
        if (!visited[u]) {
            dfs(u, adjList, visited);
        }
    }
}

int main() {
    int n = 5;  
    vector<vector<int>> adjList(n);

    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0};
    adjList[3] = {1};
    adjList[4] = {1};

    vector<bool> visited(n, false);  

    cout << "DFS traversal starting from vertex 0:" << endl;
    dfs(0, adjList, visited);

    return 0;
}
