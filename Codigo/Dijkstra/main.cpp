#include "header.hpp"

using namespace std;

int main()
{
    // Número de vértices no grafo
    int vertices = 5;

    // Criação do grafo
    Graph graph(vertices);

    // Leitura das arestas a partir de um arquivo
    readGraphFromFile("e1.txt", graph);

    // Execução do algoritmo de Dijkstra
    int startVertex = 0; // Vértice inicial
    vector<int> distances = graph.dijkstra(startVertex);

    // Exibição das distâncias mínimas a partir do vértice inicial
    for (int i = 0; i < vertices; ++i)
    {
        cout << "Distancia do vertice " << startVertex << " ao vertice " << i << ": ";
        if (distances[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << distances[i] << endl;
        }
    }

    return 0;
}
