// Bernardo Santiago Marín 
// A01638915

#include "MyGraph.h"

MyGraph::MyGraph(vector<vector<int>>& matrix) {
    this->loadGraph(matrix);
}

// Tiempo: O(n²)
// Espacio: O(n²)
void MyGraph::loadGraph(vector<vector<int>>& matrix) {
    this->matrix = matrix;
    // Para el vector de visitados, se asume que la 
    // matriz es cuadrada y simétrica sobre la diagonal principal.
    for (int i = 0; i < this->matrix.size(); i++) {
        this->visited.push_back(false); // Inicializa todos los nodos como no visitados
    }
}

// O(n)
void MyGraph::resetVisited() {
    for (int i = 0; i < this->visited.size(); i++) {
        this->visited[i] = false;
    }
}

// Tiempo: O(V + E) vertices + edges
// Espacio: O(E)
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

// Tiempo O(E)
// Espacio: O(E) (Call Stack)
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

// Tiempo: O(V + E) vertices + edges
// Espacio: O(E) (Queue)
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

// Tiempo: O(E)
// Espacio: O(E)
void MyGraph::topologicalSort(int node, stack<int> &visitStack) {
    this->visited[node] = true;

    // visitar todos los nodos adyacentes al actual
    for (int i = 0; i < this->matrix[node].size(); i++) {
        if (this->matrix[node][i] == 1 && !this->visited[i]) {
            this->topologicalSort(i, visitStack);
        }
    }
    visitStack.push(node);
}

// Tiempo: O(V+E)
// Espacio: O(E)
void MyGraph::topologicalSort() {
    stack<int> visitStack;
    this->resetVisited();
    for (int i = 0; i < this->matrix.size(); i++) {
        if (!this->visited[i]) {
            this->topologicalSort(i, visitStack);
        }
    }
    
    while (!visitStack.empty()) {
        cout << visitStack.top() << ",";
        visitStack.pop();
    }
    cout << endl;
}

// Tiempo: O(E)
// Espacio: O(E) (call stack)
bool MyGraph::isTree(int node, int &edgeCount) {
    // Cycle detected
    if (this->visited[node]) return false;

    // edgeCount == vertex - 1
    if (edgeCount >= this->matrix.size()) return false;

    // Root can't be pointed by any vertex
    if (this->matrix[node][0] != 0) return false; 

    this->visited[node] = true;
    for (int i = 0; i < this->matrix[node].size(); i++) {
        if (this->matrix[node][i] == 1) edgeCount++;
        if (this->matrix[node][i] == 1 && !this->isTree(i, edgeCount)) return false;
    }
    return true;

}

// Tiempo: O(V+E)
// Espacio: O(E)
bool MyGraph::isTree() {
    this->resetVisited();
    int edgeCount = 0;
    
    if (!this->isTree(0, edgeCount)) return false;
    return (edgeCount == this->matrix.size() - 1);
}

// Tiempo: O(V+E)
// Espacio: O(E)
bool MyGraph::bipartiteGraph() {
    queue<int> coloredQueue;
    vector<int> colors = vector<int>(this->matrix.size(), 0);

    coloredQueue.push(0);
    colors[0] = 1;
    while (!coloredQueue.empty()) {
        int u = coloredQueue.front();
        coloredQueue.pop();
        // Para cada vértice V adyacente a U si el vértice 
        // no se ha coloreado, se colorea V de color contrario 
        // a U y se mete a la cola
        for (int v = 0; v < this->matrix[u].size(); v++) {
            if (this->matrix[u][v] != 1) continue;
            if (colors[v] == 0) {
                colors[v] = (colors[u] == 1) ? 2 : 1;
                coloredQueue.push(v);
            } else {
                if (colors[u] == colors[v]) return false;
            }
        }
    }
    return true;
}

/* ------------- Ejemplo de main comentado -------------
#include "MyGraph.h"

using namespace std;

int main()
{
    vector<vector<int>> tree = {
        // A   B   C   D   E   F  G
        { 0,  1,  1,  0,  0,  0,  0 }, // A -> B -> C
        { 0,  0,  0,  1,  1,  0,  0 }, // B -> D -> E
        { 0,  0,  0,  0,  0,  1,  1 }, // C -> F -> G
        { 0,  0,  0,  0,  0,  0,  0 }, 
        { 0,  0,  0,  0,  0,  0,  0 }, 
        { 0,  0,  0,  0,  0,  0,  0 },
        { 0,  0,  0,  0,  0,  0,  0 }};

    vector<vector<int>> bipartite = {
        //A   B   C   D
        { 0,  1,  0,  1 }, // A -> B -> D
        { 1,  0,  1,  0 }, // B -> A -> C
        { 0,  1,  0,  1 },
        { 1,  0,  1,  0 }};
    
    MyGraph graph(bipartite);
    MyGraph treeGraph(tree);

    graph.DFS();
    graph.BFS();
    graph.topologicalSort();
    cout << graph.isTree() << endl;
    cout << graph.bipartiteGraph() << endl;
    
    treeGraph.DFS();
    treeGraph.BFS();
    treeGraph.topologicalSort();
    cout << treeGraph.isTree() << endl;
    cout << treeGraph.bipartiteGraph() << endl;

    return 0;
}

*/