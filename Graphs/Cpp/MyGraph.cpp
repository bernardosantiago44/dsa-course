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

void MyGraph::resetVisited() {
    for (int i = 0; i < this->visited.size(); i++) {
        this->visited[i] = false;
    }
}

void MyGraph::DFS() {
    this->resetVisited();
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
    this->resetVisited();

    int start = this->matrix[0][0]; // Empezamos con el nodo 0
    queue<int> q;
    this->visited[0] = true;
    cout << 0 << ",";
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // Recorrer los nodos adyacentes a current
        for (int i = 0; i < this->matrix[current].size(); i++) {
            int currentAdy = this->matrix[current][i];
            if (currentAdy == 1 && this->visited[i] == false) {
                this->visited[i] = true;
                cout << i << ",";
                q.push(i);
            }
        }
    }
    cout << endl;
}

void MyGraph::print() {
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[0].size(); j++) {
            cout << this->matrix[i][j];
        }
        cout << endl;
    }
}

/* ------------- Ejemplo de main comentado -------------
#include "MyGraph.h"

using namespace std;

int main()
{
    vector<vector<int>> adj_matrix = {
        {0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0}};

    vector<vector<int>> matrix2 = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    
    MyGraph graph(adj_matrix);
    graph.DFS();
    graph.BFS();

    graph.loadGraph(matrix2);
    graph.DFS();
    graph.BFS();
    return 0;
}

*/