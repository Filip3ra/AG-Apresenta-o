#include "header.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void readGraphFromFile(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int u, v, w;
        if (iss >> u >> v >> w) {
            graph.addEdge(u, v, w);
        }
    }

    file.close();
}
