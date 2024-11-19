#include "MyGraph.h"

using namespace std;

int main() {
    vector<vector<int>> adj_matrix = {
    {0, 1, 1, 0},  // Nodo 0 está conectado con 1 y 2
    {1, 0, 0, 1},  // Nodo 1 está conectado con 0 y 3
    {1, 0, 0, 1},  // Nodo 2 está conectado con 0 y 3
    {0, 1, 1, 0}   // Nodo 3 está conectado con 1 y 2
};
    MyGraph graph(adj_matrix);
    graph.DFS();

    return 0;
}