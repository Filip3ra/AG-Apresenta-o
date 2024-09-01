#include "header.hpp"

using namespace std;

Graph::Graph(int vertices) : vertices(vertices)
{
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight)
{
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight); // Se o grafo for não-direcionado
}

vector<int> Graph::dijkstra(int start)
{
    vector<int> dist(vertices, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : adjList[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
