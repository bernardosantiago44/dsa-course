// Bernardo Santiago Marín 
// A01638915

#include "MyGraph.h"

MyGraph::MyGraph(vector<vector<int>>& matrix) {
    this->loadGraph(matrix);
}

void MyGraph::loadGraph(vector<vector<int>>& matrix) {
    this->matrix = matrix;
    // Para el vector de visitados, se asume que la 
    // matriz es cuadrada y simétrica sobre la diagonal principal.
    for (int i = 0; i < this->matrix.size(); i++) {
        this->visited.push_back(false); // Inicializa todos los nodos como no visitados
    }
}

void MyGraph::DFS() {
    // Inicia el DFS desde el nodo en [0, 0].
    for (int i = 0; i < this->matrix.size(); i++) {
        if (!this->visited[i]) {
            this->DFS(i); // Hacer DFS a partir del nodo actual (columna actual)
        }
    }
    cout << endl;
}

void MyGraph::DFS(int node) {
    this->visited[node] = true;
    cout << node << ","; 

    // Continuar el DFS en la fila del nodo actual
    for (int i = 0; i < this->matrix[node].size(); i++) {
        // Si hay conexión con el nodo actual y no está visitado
        if (this->matrix[node][i] == 1 && !this->visited[i]) {
            this->DFS(i);
        }
    }
}

void MyGraph::BFS() {

}

void MyGraph::print() {
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[0].size(); j++) {
            cout << this->matrix[i][j];
        }
        cout << endl;
    }
}