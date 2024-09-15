#include "header.hpp"
#include <iostream>
#include <limits>

Graph::Graph(int V, int E) : V(V), E(E) {}

void Graph::addEdge(int u, int v, int w)
{
    edges.push_back({u, v, w});
}

void Graph::bellmanFord(int src)
{
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (const auto &edge : edges)
    {
        if (dist[edge.u] != numeric_limits<int>::max() && dist[edge.u] + edge.w < dist[edge.v])
        {
            cout << "O grafo contém ciclo de peso negativo!" << endl;
            return;
        }
    }
    /* Para imprimir as distâncias
        cout << "Distancias do vertice origem " << src << ":" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertice " << i << " : " << dist[i] << endl;
        }
        */
}
