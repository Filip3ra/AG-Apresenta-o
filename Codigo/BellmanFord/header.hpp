#pragma once
#include <vector>
#include <string>

using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    void bellmanFord(int src);
};

// Funções para lidar com arquivo
void readGraphFromFile(const string& filename, Graph& graph);
