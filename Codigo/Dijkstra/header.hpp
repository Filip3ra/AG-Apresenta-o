#pragma once

#include <vector>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph
{
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    vector<int> dijkstra(int start);

private:
    int vertices;
    vector<vector<pair<int, int>>> adjList;
};

void readGraphFromFile(const string &filename, Graph &graph);
