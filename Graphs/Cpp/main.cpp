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