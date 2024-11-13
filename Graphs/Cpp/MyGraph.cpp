// Bernardo Santiago Marín 
// A01638915

#include "MyGraph.h"

MyGraph::MyGraph(vector<vector<int>>& matrix) {
    this->loadGraph(matrix);
}

void MyGraph::loadGraph(vector<vector<int>>& matrix) {
    this->matrix = matrix;
}

void MyGraph::DFS() {

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