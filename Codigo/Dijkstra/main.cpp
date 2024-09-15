#include "header.hpp"
#include <iostream>
#include <chrono> // Para medir o tempo de execução

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
    // Verificar se os dois argumentos (número de nós e nome do arquivo) foram passados
    if (argc < 3)
    {
        cerr << "Uso: " << argv[0] << " <numero_de_nos> <nome_do_arquivo>" << endl;
        return 1;
    }

    // Converte o primeiro argumento (quantidade de nós) para um inteiro
    int vertices = stoi(argv[1]);

    string filename = argv[2];

    Graph graph(vertices);

    readGraphFromFile(filename, graph);

    int startVertex = 0; // Vértice inicial

    auto start_time = high_resolution_clock::now(); // Tempo inicial
    vector<int> distances = graph.dijkstra(startVertex);
    auto end_time = high_resolution_clock::now(); // Tempo final

    int x = 1000; // Destino

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

    // cout << "Distancia do vertice " << startVertex << " ao vertice " << i << ": " << distances[x] << endl;

    // Calcula a duração em milissegundos
    auto duration = duration_cast<milliseconds>(end_time - start_time);
    cout << "Tempo de execucao do algoritmo: " << duration.count() << " milissegundos" << endl;

    return 0;
}
