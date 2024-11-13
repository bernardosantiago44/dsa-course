#include "MyGraph.h"

using namespace std;

int main() {
    vector<vector<int>> adj_matrix = {{0, 1, 0, 0},
                                      {1, 0, 1, 0},
                                      {1, 1, 0, 0},
                                      {1, 1, 1, 0}};
    MyGraph graph(adj_matrix);
    graph.print();

    return 0;
}