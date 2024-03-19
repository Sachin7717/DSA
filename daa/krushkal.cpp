#include <iostream>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

struct Graph {
    int V, E;
    Edge* edges;

    Graph(int v, int e) {
        V = v;
        E = e;
        edges = new Edge[e];
    }

    void addEdge(int src, int dest, int weight, int index) {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(Graph& graph) {
    Edge result[graph.V]; 
    int e = 0; 
    int i = 0;
    int V = graph.V; 
    Edge* edges = graph.edges; 

    for (i = 0; i < graph.E; ++i) {
        for (int j = i + 1; j < graph.E; ++j) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    Subset* subsets = new Subset[V];

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    i = 0; 
    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    cout << "Edges in the constructed MST:" << endl;
    for (i = 0; i < e; ++i) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }

    delete[] subsets;
}

int main() {
    int V = 4; 
    int E = 5; 
    Graph graph(V, E);

    graph.addEdge(0, 1, 10, 0);
    graph.addEdge(0, 2, 6, 1);
    graph.addEdge(0, 3, 5, 2);
    graph.addEdge(1, 3, 15, 3);
    graph.addEdge(2, 3, 4, 4);

    KruskalMST(graph);

    return 0;
}
