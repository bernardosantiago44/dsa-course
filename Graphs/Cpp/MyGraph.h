#pragma once
#include <vector>

using namespace std;

class MyGraph {
    private:
        vector<vector<int>> matriz;

        MyGraph(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz);
        void DFS();
        void BFS();
};