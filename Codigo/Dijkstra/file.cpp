#include "header.hpp"

using namespace std;

void readGraphFromFile(const string &filename, Graph &graph)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int u, v, weight;
        if (!(iss >> u >> v >> weight))
        {
            break;
        } // Verifica se a linha é válida
        graph.addEdge(u, v, weight);
    }

    file.close();
}
