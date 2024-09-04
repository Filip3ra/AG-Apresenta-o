#include "header.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Uso: " << argv[0] << " <número de vértices> <número de arestas> <nome do arquivo>" << endl;
        return 1;
    }

    int V = stoi(argv[1]);     // Número de vértices
    int E = stoi(argv[2]);     // Número de arestas
    string filename = argv[3]; // Nome do arquivo

    Graph graph(V, E);

    readGraphFromFile(filename, graph);

    int src = 0; // Vértice de origem
    graph.bellmanFord(src);

    return 0;
}
