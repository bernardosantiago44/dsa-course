#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MyGraph {
    public:
        MyGraph(vector<vector<int>>& matrix);
        void print();
        void DFS();
        void BFS();
    // private:
        vector<vector<int>> matrix;
        vector<bool> visited = {};

        void resetVisited();
        void loadGraph(vector<vector<int>>& matrix);
        void DFS(int node);
};