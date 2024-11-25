#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class MyGraph {
    public:
        MyGraph(vector<vector<int>>& matrix);
        void print();
        void DFS();
        void BFS();

        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
    // private:
        vector<vector<int>> matrix;
        vector<bool> visited = {};

        void resetVisited();
        void loadGraph(vector<vector<int>>& matrix);
        void DFS(int node);

        void topologicalSort(int node, stack<int> &visitStack);
        
        bool isTree(int node, int &edgeCount);
};