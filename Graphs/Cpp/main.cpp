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