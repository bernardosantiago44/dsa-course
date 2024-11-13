#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MyGraph {
    public:
        MyGraph(vector<vector<int>>& matrix);
        void print();
    private:
        vector<vector<int>> matrix;

        void loadGraph(vector<vector<int>>& matrix);
        void DFS();
        void BFS();
};