#include "header.hpp"
#include <iostream>
#include <chrono> // Para medir o tempo de execução

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Uso: " << argv[0] << " <número de vértices> <número de arestas> <nome do arquivo>" << endl;
        return 1;
    }

    /* nome de cada arquivo possui o número de vértices e arestas
       Ex: graph_1500_10k.txt tem 1500 vértices e 10000 arestas
    */
    int V = stoi(argv[1]);     // Número de vértices
    int E = stoi(argv[2]);     // Número de arestas
    string filename = argv[3]; // Nome do arquivo

    Graph graph(V, E);

    readGraphFromFile(filename, graph);

    int src = 0; // Vértice de origem

    auto start_time = high_resolution_clock::now(); // Tempo inicial
    graph.bellmanFord(src);
    auto end_time = high_resolution_clock::now(); // Tempo final

    // Calcula a duração em milissegundos
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "Tempo de execucao do algoritmo: " << duration.count() << " milissegundos" << endl;

    return 0;
}
