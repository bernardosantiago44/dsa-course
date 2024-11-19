#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MyGraph {
    public:
        MyGraph(vector<vector<int>>& matrix);
        void print();
        void DFS();
    private:
        vector<vector<int>> matrix;
        vector<bool> visited = {};

        void loadGraph(vector<vector<int>>& matrix);
        void DFS(int node);
        void BFS();
};